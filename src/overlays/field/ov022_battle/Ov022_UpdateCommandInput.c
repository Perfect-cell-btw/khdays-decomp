/* ov022: the local player's command-input dispatcher.
 *
 * Reached from the per-frame actor tick once the actor is confirmed to belong
 * to the local player. It first accumulates a suppression flag from four
 * independent tests and, if any fires, blanks the two-byte menu state and
 * leaves. Otherwise it builds the 15-slot command mask -- optionally split
 * across the two screens -- pushes the mask and the target selection to the
 * HUD, walks the command menu from the button globals, and finally records the
 * chosen command kind and its arguments in the actor.
 *
 * Both 64-bit flag words are read here: the one at 0x00 and the one at 0x464.
 */

#include "nitro/types.h"

#include "game/config.h"
struct Equip {
    u8 pad00[0x17];
    u8 nKind;                    /* 0x17 */
};

struct Actor {
    unsigned long long nFlags;   /* 0x000 */
    u8 pad008[1];
    u8 nId;                      /* 0x009 */
    u8 pad00a[8];
    u16 nHp;                     /* 0x012 */
    u8 pad014[0x10];
    u32 nField24;                /* 0x024 */
    u8 pad028[0x43c];
    unsigned long long nFlags2;  /* 0x464 */
    u8 pad46c[0x64];
    signed char nCommandKind;    /* 0x4d0 */
    u8 pad4d1[1];
    u16 nCmdArg;                 /* 0x4d2 */
    u16 nCmdArg2;                /* 0x4d4 */
    u8 pad4d6[0x12];
    u8 bHudFlag : 1;             /* 0x4e8 bit 0 */
    u8 bMenuFlag : 1;            /* bit 1 */
    u8 nPad4e8 : 1;
    u8 bIdleFlag : 1;            /* bit 3 */
    u8 nRest4e8 : 4;
    u8 pad4e9[0xf];
    struct Equip *pEquip;        /* 0x4f8 */
    u8 pad4fc[0x1d8c];
    short slotMask;              /* 0x2288 */
    u8 pad228a[0x6e];
    u8 stateBlk;                 /* 0x22f8 */
    u8 pad22f9[0x7bf];
    u8 nMenuState;               /* 0x2ab8 */
};

struct ScreenCfg {
    u8 pad00[4];
    u16 nSplit;                  /* 0x04 */
};

extern u8 data_0204c240;
extern struct ScreenCfg data_0204c254;
extern u16 gPadHeld;
extern u16 gPadPressed;

extern char *Ov022_GetGlobalPlusE0(void);
extern int func_ov022_020ab350(struct Actor *pActor);
extern int Ov002_RunShutdownHook(void);
extern int Session_GetLocalPlayerIndex(void);
extern int PauseMenu_GetMode(void);
extern int func_ov022_0209029c(short *pMask, int nSlot);
extern int Load2DArrayU8(int nId, int nSlot);
extern void Ov002_HudSetSlotValue(int nSlot, int nKind);
extern int GameState_IsFlagSet(int nFlag);
extern int Ov002_GetStateWord(void);
extern int func_ov022_02095450(u8 *pBlk);
extern void Ov002_PanelSetHelpVisible(int nMask);
extern void Ov002_UpdateVisibleColumnMask(int bOn);
extern void Ov002_SetColumnBit(int nSlot, int nOn);
extern void Ov002_PanelSelectSource(int nTarget, int nArg);
extern int Ov022_GetSubKindIfState2(struct Actor *pActor);
extern int Ov022_IsState9Or6WithFlag200(u8 *pBlk);
extern int Ov002_IsObjectFree(struct Equip *pEquip, int nId);
extern int func_ov022_0209fc78(struct Actor *pActor, int nSlot);
extern int Ov022_IsInputAllowedForActiveSlot(void);
extern int GameState_GetField(int nFlag, int nWhich);
extern int Ov002_Hud_IsPanelOpen(void);
extern void Ov002_Hud_SetSecondaryFlag(int bOn);
extern void Ov002_SelectShortcut(int nCommand);
extern int Ov002_IsMissionClearFinished(int nWhich);
extern void Ov002_Hud_ActivatePanelSlot(void);
extern void Ov002_RequestCrawlSkip(void);
extern int Ov002_AcceptRequestAndNotify(int nWhich);
extern void Ov002_PanelCursorNext(void);
extern int func_ov022_02083f0c(void);
extern int Ov002_IsObjectFlag2000Set(int nSlot);
extern unsigned short Ov022_GetRepeatKeys(void);
extern void Ov002_PanelCursorPrev(void);
extern void Ov002_PanelCursorStepLeft(void);
extern void Ov002_PanelCursorStepRight(void);
extern unsigned short Ov002_GetPanelField01a4(void);
extern u16 Ov002_Panel_GetSelectedCellArg(void);
extern u16 Ov002_LookupRowLabel(void);
extern u16 Ov002_GetCachedEntryField0(void);
extern u16 Ov002_GetCachedEntryField2(void);
extern int Ov002_Panel_GetCursor(void);
extern int Ov002_Panel_GetState(void);

void Ov022_UpdateCommandInput(struct Actor *pActor)
{
    char *pMenu;
    int bCommandChosen;
    int bSuppress;
    int bLock;
    int bMenuActive;
    int bAllySel;
    int i;
    int uMask;
    int nArg;
    int nAim;
    int bBtn;
    int bNoRepeat;
    int nBtn;
    int nCmd;
    int nGlobal;
    int bOk;

    pMenu = Ov022_GetGlobalPlusE0();
    bCommandChosen = 0;
    bSuppress = 0;
    bLock = 0;
    bMenuActive = 0;
    bAllySel = 0;

    if (func_ov022_020ab350(pActor) != 0 || Ov002_RunShutdownHook() != 0) {
        bSuppress = 1;
    }
    if ((pActor->nFlags2 & (1ULL << 29)) != 0
        || (pActor->nFlags & (1ULL << 10)) != 0
        || (pActor->nFlags & (1ULL << 45)) != 0) {
        bSuppress = 1;
    }
    if (Session_GetLocalPlayerIndex() == 0 && (data_0204c240 & 4) != 0
        && PauseMenu_GetMode() == 2) {
        bSuppress = 1;
    }
    if (pActor->nHp == 0) {
        bSuppress = 1;
    }
    if (bSuppress != 0) {
        pMenu[0] = 0;
        pMenu[1] = 0;
        return;
    }

    if (pActor->nMenuState == 2 || pActor->nMenuState == 3) {
        bLock = 1;
    }
    if ((pActor->nFlags & (1ULL << 13)) != 0) {
        bLock = 1;
    }
    if ((pActor->nFlags & (1ULL << 11)) != 0
        || (pActor->nFlags2 & (1ULL << 38)) != 0) {
        pActor->nFlags |= (1ULL << 11);
        bLock = 1;
    }

    uMask = 0;
    for (i = 0; i < 15; i++) {
        if (func_ov022_0209029c(&pActor->slotMask, i) != 0) {
            Ov002_HudSetSlotValue((u8)i, (u8)Load2DArrayU8(pActor->nId, i));
            if ((data_0204c240 & 2) == 0
                || (((data_0204c254.nSplit & 1) == 0 || i >= 12)
                    && ((data_0204c254.nSplit & 2) == 0 || i < 12))) {
                uMask = (u16)(uMask | (1 << i));
            }
        }
    }
    if (GameState_IsFlagSet(0x20e0) != 0) {
        uMask = 0;
    }
    if (Ov002_GetStateWord() == 0x6c && (data_0204c240 & 4) == 0) {
        uMask = 0;
    }
    if (pActor->nMenuState == 6) {
        uMask = 0;
    }
    if (bLock != 0 || func_ov022_02095450(&pActor->stateBlk) != 0) {
        uMask = 0;
    }
    Ov002_PanelSetHelpVisible(uMask);

    if (bLock != 0 || func_ov022_02095450(&pActor->stateBlk) != 0
        || (pActor->nFlags & (1ULL << 26)) != 0) {
        Ov002_UpdateVisibleColumnMask(0);
    } else {
        Ov002_UpdateVisibleColumnMask(1);
        if ((data_0204c240 & 2) != 0 && (data_0204c254.nSplit & 4) != 0) {
            for (i = 2; i <= 11; i++) {
                Ov002_SetColumnBit(i, 0);
            }
        }
    }

    if (bLock != 0) {
        Ov002_PanelSelectSource(-1, 0);
    } else {
        nAim = Ov022_GetSubKindIfState2(pActor);
        if (nAim != -1
            && (pActor->nFlags2 & (1ULL << 16)) == 0
            && Ov022_IsState9Or6WithFlag200(&pActor->stateBlk) == 0) {
            nArg = Ov002_IsObjectFree(pActor->pEquip, pActor->nId);
            if (pActor->pEquip->nKind != 0) {
                if ((pActor->nField24 & 4) == 0) {
                    if ((Ov022_GetSubKindIfState2(pActor) & 0x80) == 0) {
                        nArg = 0;
                    }
                } else if ((pActor->nFlags & (1ULL << 36)) != 0
                           && (pActor->nFlags2 & (1ULL << 7)) != 0) {
                    nArg = 0;
                }
            }
            if (pActor->pEquip->nKind == 0) {
                bAllySel = 1;
            }
            Ov002_PanelSelectSource(Ov022_GetSubKindIfState2(pActor) & 0xf, nArg);
        } else {
            bAllySel = 1;
            if (func_ov022_0209fc78(pActor, -1) == 0) {
                bAllySel = 0;
            }
            Ov002_PanelSelectSource(0, bAllySel);
        }
    }

    if (func_ov022_020ab350(pActor) == 0
        && Ov022_IsInputAllowedForActiveSlot() == 0 && bLock == 0) {
        bBtn = 0;
        if (GameState_GetField(CONFIG_CONTROLS, 1) == 0) {
            if ((gPadHeld & 0x200) != 0) {
                bBtn = 1;
            }
        } else if ((gPadHeld & 0x100) != 0
                   && (gPadHeld & 0x200) != 0) {
            bBtn = 1;
        }
        if (bBtn != 0 && Ov002_Hud_IsPanelOpen() == 0
            && (pActor->nFlags2 & (1ULL << 29)) == 0
            && func_ov022_02095450(&pActor->stateBlk) == 0) {
            bMenuActive = 1;
        }
        Ov002_Hud_SetSecondaryFlag(bMenuActive);
        if (bMenuActive != 0) {
            nCmd = -1;
            nBtn = gPadPressed;
            if ((nBtn & 1) != 0) {
                nCmd = 0;
            }
            if ((nBtn & 2) != 0) {
                nCmd = 3;
            }
            if ((nBtn & 0x800) != 0) {
                nCmd = 2;
            }
            if ((nBtn & 0x400) != 0) {
                nCmd = 1;
            }
            if (nCmd < 0) {
                bMenuActive = 0;
            } else {
                Ov002_SelectShortcut(nCmd);
                bCommandChosen = 1;
            }
        } else {
            bNoRepeat = 1;
            if (Ov002_IsMissionClearFinished(bNoRepeat) != 0) {
                bNoRepeat = 0;
            }
            if ((gPadPressed & 1) != 0) {
                bCommandChosen = 1;
                Ov002_Hud_ActivatePanelSlot();
                if (bNoRepeat != 0) {
                    Ov002_RequestCrawlSkip();
                }
            } else if ((gPadPressed & 2) != 0) {
                pActor->bHudFlag = (u8)Ov002_AcceptRequestAndNotify(1);
                if (bNoRepeat != 0) {
                    Ov002_RequestCrawlSkip();
                }
            }
            if ((gPadPressed & 0x800) != 0 && bNoRepeat != 0) {
                Ov002_RequestCrawlSkip();
            }
            if (GameState_GetField(CONFIG_COMMAND_LIST, 1) != 0) {
                if ((gPadPressed & 0x400) != 0
                    && Ov002_Hud_IsPanelOpen() == 0 && bCommandChosen == 0) {
                    Ov002_PanelCursorNext();
                }
            } else {
                nGlobal = func_ov022_02083f0c();
                bOk = 1;
                if ((gPadPressed & 0x400) != 0
                    && Ov002_Hud_IsPanelOpen() == 0 && bCommandChosen == 0) {
                    pMenu[0] = 1;
                    pMenu[1] = 1;
                }
                if ((gPadHeld & 0x400) != 0) {
                    if (nGlobal != -1 && Ov002_IsObjectFlag2000Set(nGlobal) != 0) {
                        bOk = 0;
                    }
                    if (pMenu[1] == 1) {
                        if ((gPadHeld & 0xf0) == 0) {
                            pMenu[1] = 2;
                        }
                    } else if (pMenu[1] == 2 && bOk != 0) {
                        if ((Ov022_GetRepeatKeys() & 0x80) != 0) {
                            pMenu[0] = 0;
                            Ov002_PanelCursorNext();
                        } else if ((Ov022_GetRepeatKeys() & 0x40) != 0) {
                            pMenu[0] = 0;
                            Ov002_PanelCursorPrev();
                        } else if ((gPadPressed & 0x20) != 0) {
                            pMenu[0] = 0;
                            Ov002_PanelCursorStepLeft();
                        } else if ((gPadPressed & 0x10) != 0) {
                            pMenu[0] = 0;
                            Ov002_PanelCursorStepRight();
                        }
                    }
                } else {
                    pMenu[1] = 0;
                    if (pMenu[0] > 0) {
                        pMenu[0] = 0;
                        Ov002_PanelCursorNext();
                    }
                }
            }
        }
    }

    if (bCommandChosen != 0) {
        pActor->nCommandKind = (signed char)Ov002_GetPanelField01a4();
        if (Ov002_Hud_IsPanelOpen() != 0 && pActor->nCommandKind != 9) {
            pActor->nCommandKind = 7;
        }
        switch (pActor->nCommandKind) {
        case 8:
            pActor->nCmdArg = Ov002_Panel_GetSelectedCellArg();
            break;
        case 11:
            pActor->nCmdArg = Ov002_LookupRowLabel();
            break;
        case 12:
        case 13:
            pActor->nCmdArg = Ov002_GetCachedEntryField0();
            pActor->nCmdArg2 = Ov002_GetCachedEntryField2();
            break;
        default:
            pActor->nCmdArg = 0;
            break;
        }
        pActor->bMenuFlag = (u8)bMenuActive;
    }
    if (Ov002_Panel_GetCursor() == 0 && Ov002_Panel_GetState() == 0
        && bAllySel != 0) {
        pActor->bIdleFlag = 1;
        return;
    }
    pActor->bIdleFlag = 0;
}
