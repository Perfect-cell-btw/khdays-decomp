/*
 * Runs one frame of the multiplayer session screen and hands back the next
 * state, or nothing to stay where it is.
 *
 * While this machine owns the session and its countdown is still running, the
 * countdown is stepped once a frame and fires its expiry hook when it reaches
 * zero. The peer mask is then rebuilt from scratch: bit four always, plus one
 * bit per peer that answers the poll.
 *
 * From there the frame is a cascade of gates, each of which can hand back a
 * different state: the cancel and back flags, the two join requests, the give
 * up path, a pending command to retire, the queued slot request, and finally
 * the state seven gate that leaves for the shop when the right combination of
 * global flags is set. If none of them fires, the screen's own per-frame
 * handler runs and can ask for a state change itself.
 *
 * Four things here are load-bearing rather than style.
 *
 * The peer-mask update in the loop takes no cast. Written with one the compiler
 * masks to a byte explicitly and loses the predication the original uses.
 *
 * The two places that clear bit four and set bit five are written as two
 * compound assignments, the clear then the set. Written as one assignment the
 * compiler updates the loaded value in place instead of computing the clear
 * into a register of its own.
 *
 * The silencer branch tests for the flag being clear, not set, so its two arms
 * come out in the original's order.
 *
 * The pending command is retired by a helper that takes both the command's kind
 * byte and the command itself. That second argument is why the original keeps
 * the pointer in its own register rather than reading the byte over it.
 *
 * ARM.
 */

#include "nitro/types.h"

typedef struct Ov002SessionLink {
    char pad000[2];
    s16 nSubState;
    char pad004[4];
    int nFieldA;
    int nFieldB;
    char pad010[8];
    int nSavedSubState;
} Ov002SessionLink;

typedef struct Ov002SessionPeer {
    char pad000[0xc];
    s8 nReady;
} Ov002SessionPeer;

typedef struct Ov002SessionScreen {
    char pad0000[0x8b40];
    s8 nPending;
    u8 nSlotByte;
    char pad8b42[0x16];
    int nState;
    char pad8b5c[4];
    int nSlotIndex;
    int nFlags;
    u8 nMask;
    char pad8b69[0x27];
    void *(*pHandler)(void);
    char pad8b94[0x14];
    Ov002SessionLink link;
    char pad8bc4[0x1a8];
    Ov002SessionPeer peer;
    char pad8d7d[0x1f];
    s16 nCountdown;
    char pad8d9a[0x22];
    u8 *pCommand;
} Ov002SessionScreen;

extern u8 data_0204be04;
extern u8 data_0204c240;
extern u16 data_0204c190;
extern u16 data_0204c18c;

extern Ov002SessionScreen *NNSi_FndGetCurrentRootHeap(void);
extern void NNSi_FndFreeFromDefaultHeap(void *pBlock);
extern int Session_GetLocalPlayerIndex(void);
extern int Session_IsReady(void);
extern int GameState_GetField(int a, int b);
extern void PauseMenu_SetMode(int a);
extern void PauseMenu_SetAllowed(int a);
extern void PlaySound(int a, int b);
extern int QueryActiveStateOrDelegate(void);
extern int *GetEntryField20ByIndex(int a);
extern int Ov002_RunShutdownHook(void);
extern int Ov002_Hud_IsPanelOpen(void);
extern void Ov002_AwardCatchUpTally(void);
extern void Ov002_SendTallyUpdate(void);
extern int Ov002_IsSessionOpen(void);
extern int func_ov022_020882f8(void);
extern int Ov002_AskPiecesAboutPeer(int a, int b);
extern int Ov002_GlyphExists(int a);
extern int Ov002_StepGiveUpTimer(void);
extern void Ov002_BeginSessionTeardown(int a);
extern void Ov002_FlushPendingPeerNotices(void);
extern int Ov002_BuildSessionCommand(int nKind, const u8 *pCommand);
extern void Ov002_StepIdleNudge(void);
extern void Ov002_SetSessionBusy(int a);
extern void Ov002_SetSessionActive(int a, int b);
extern void Ov002_SetLeaveRequest(int a);
extern void Ov002_ResetAllSlots(void);
extern int Ov002_Roster_GetFirstMember(void);
extern int Ov002_CanAcceptSlotRequest(void);
extern int Ov002_RequestLinkSlot2(int a);
extern int Ov002_RequestLinkSlot3(void);
extern void Ov002_RequestCrawlSkip(void);
extern int func_ov022_02088648(void);
extern int func_ov022_020886d0(int a);
extern int Ov002_List_GetSlot(int a);
extern void Ov002_Roster_Reset(void);
extern void Ov002_RunPendingCallbacks(void);
extern void Ov002_SessionChoiceCommitted(void);
extern void Ov002_PickSavePromptStep(void);

void *Ov002_SessionTick(void)
{
    Ov002SessionScreen *pSess;
    Ov002SessionLink *pLink;
    void *pNext;
    Ov002SessionPeer *pPeer;
    int i;
    int nSlot;

    pNext = 0;
    pSess = NNSi_FndGetCurrentRootHeap();
    pLink = &pSess->link;
    pPeer = &pSess->peer;
    if (data_0204be04 != 0) {
        return pNext;
    }

    if (Session_GetLocalPlayerIndex() == 0 && pSess->nCountdown >= 0
        && Ov002_RunShutdownHook() == 0 && Ov002_Hud_IsPanelOpen() == 0) {
        pSess->nCountdown = (s16)(pSess->nCountdown - 1);
        if (pSess->nCountdown <= 0) {
            Ov002_AwardCatchUpTally();
            pSess->nCountdown = -1;
        }
    }

    Ov002_SendTallyUpdate();
    pSess->nMask = 0x10;
    if (Ov002_IsSessionOpen() != 0) {
        i = 0;
        if (func_ov022_020882f8() > 0) {
            do {
                if (Ov002_AskPiecesAboutPeer(i, -0x1000) != 0) {
                    pSess->nMask |= 1 << i;
                }
                i++;
            } while (i < func_ov022_020882f8());
        }
    }

    if (pSess->nState == 7 || pSess->nState == 1 || pSess->nState == 5) {
        if ((pSess->nFlags & 0x40) != 0) {
            pLink->nFieldA = 0;
            pLink->nFieldB = 0;
            return Ov002_RunPendingCallbacks;
        }
        if ((pSess->nFlags & 4) != 0) {
            pLink->nFieldA = 0;
            if ((data_0204c240 & 4) != 0) {
                pLink->nFieldB = -1;
                pLink->nSubState = -3;
            } else {
                pLink->nFieldB = 0;
            }
            return Ov002_RunPendingCallbacks;
        }
        if ((pSess->nFlags & 0x22) != 0) {
            return 0;
        }
        if (Session_IsReady() != 0) {
            if ((pSess->nFlags & 0x10) != 0) {
                if (Ov002_GlyphExists(1) != 0) {
                    pSess->nFlags = (pSess->nFlags & ~0x10) | 0x20;
                    return 0;
                }
            } else if ((pSess->nFlags & 1) != 0) {
                if (Ov002_GlyphExists(0) != 0) {
                    pSess->nFlags = (pSess->nFlags & ~1) | 2;
                    return 0;
                }
            }
        }
        if (Ov002_StepGiveUpTimer() != 0 && Session_GetLocalPlayerIndex() == 0) {
            if ((data_0204c240 & 4) != 0) {
                Ov002_BeginSessionTeardown(0);
            }
            return 0;
        }
    }

    Ov002_FlushPendingPeerNotices();
    if (pSess->pCommand != 0
        && Ov002_BuildSessionCommand(pSess->pCommand[0], pSess->pCommand) != 0xffff) {
        NNSi_FndFreeFromDefaultHeap(pSess->pCommand);
        pSess->pCommand = 0;
    }
    Ov002_StepIdleNudge();

    if (pSess->nState == 7 || pSess->nState == 1 || pSess->nState == 5) {
        if (pSess->nPending != 0) {
            pSess->nPending = 0;
            if ((data_0204c240 & 4) == 0) {
                Ov002_SetSessionBusy(1);
            } else {
                PauseMenu_SetMode(0);
            }
            PauseMenu_SetAllowed(0);
            Ov002_SetSessionActive(1, pSess->nSlotByte);
            pSess->nSlotByte = 0xff;
            pSess->nMask &= ~0x10;
            pSess->nMask |= 0x20;
            Ov002_SetLeaveRequest(0);
            return Ov002_SessionChoiceCommitted;
        }
        if (pPeer->nReady >= 0) {
            pSess->nFlags &= ~0x100;
            if ((data_0204c240 & 4) != 0) {
                PauseMenu_SetMode(0);
            }
            Ov002_SetSessionActive(1, 0xff);
            Ov002_ResetAllSlots();
            return Ov002_RunPendingCallbacks;
        }
    }

    nSlot = Ov002_Roster_GetFirstMember();
    if (nSlot != -1 && Ov002_CanAcceptSlotRequest() != 0) {
        if (Session_IsReady() != 0) {
            if (Ov002_RequestLinkSlot2(nSlot) == 0) {
                return 0;
            }
            if ((data_0204c240 & 4) != 0) {
                PauseMenu_SetMode(0);
            }
            PauseMenu_SetAllowed(0);
            if ((data_0204c240 & 4) == 0) {
                Ov002_SetSessionBusy(1);
            }
        } else {
            if (Ov002_RequestLinkSlot3() == 0) {
                return 0;
            }
        }
        pSess->nMask &= ~0x10;
        pSess->nMask |= 0x20;
        pSess->nSlotIndex = nSlot;
        Ov002_RequestCrawlSkip();
        return Ov002_PickSavePromptStep;
    }

    if (pSess->nState == 7
        && ((data_0204c190 & 8) != 0
            || ((data_0204c190 & 0x800) != 0 && (data_0204c18c & 0x200) == 0
                && (u32)GameState_GetField(0, 9) >= 0xb))
        && func_ov022_02088648() == 0 && Ov002_RunShutdownHook() == 0
        && func_ov022_020886d0(0) == 0 && pSess->nPending == 0) {
        if ((GetEntryField20ByIndex(QueryActiveStateOrDelegate())[9] & 4) != 0) {
            if (Ov002_List_GetSlot((u16)QueryActiveStateOrDelegate()) == 0) {
                pLink->nSavedSubState = pLink->nSubState;
                pLink->nSubState = (data_0204c190 & 8) != 0 ? -2 : -7;
                Ov002_SetSessionBusy(1);
                Ov002_ResetAllSlots();
                Ov002_Roster_Reset();
                Ov002_SetSessionActive(1, 0xff);
                PlaySound(0, 2);
                pSess->nMask &= ~0x10;
                return Ov002_RunPendingCallbacks;
            }
        }
    }

    if (pSess->pHandler != 0) {
        if (pSess->pHandler() != 0) {
            Ov002_ResetAllSlots();
            pSess->nMask &= ~0x10;
            pNext = Ov002_RunPendingCallbacks;
        }
    }
    return pNext;
}
