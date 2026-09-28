
#include "nitro/types.h"

extern u8 data_0204be04;
extern const char data_ov002_0207f480[];

extern int QueryActiveStateOrDelegate(void);
extern void Ov002_SetRosterHighlight(char *pElement, int nIndex, int bOn);
extern int Ov002_Hud_IsPanelOpen(void);
extern int Ov002_GetRootField8b68Alt(void);
extern void func_02020878(int nMode);
extern void Ov002_SetLeaveRequest(int bOn);
extern int Ov002_GetPhaseWord(void);
extern int Ov002_GetRootField8b41(void);
extern void Ov002_SetRootField8b41(u8 nBits);
extern void Ov002_SetRootField8b40(void);
extern void Ov002_SetSessionActive(int nKind, u8 nBits);
extern int GameState_IsFlagSet(int nField);
extern void Ov002_SubmitRequestRecord(int a, int b, int c, int d);
extern int func_ov022_02083f0c(void);
extern int func_ov022_02083f5c(void);
extern int func_ov022_02083f40(void);
extern void func_ov022_02086818(int nHandle, int nMode);
extern void Ov002_SetOrClearFlag200(int nHandle, int nMode);
extern void Ov002_Camera_SetMode(int nHandle, int nMode, void *pExtra);
extern int Ov002_GetPanelRequestBlock(void);
extern void Ov002_StreamFormattedLine(const char *pName, void *pText);
extern int Session_GetLocalPlayerIndex(void);
extern void Ov002_BeginSessionTeardown(int nMode);
extern void Ov002_SetSessionBusy(int nMode);
extern void Ov002_SetPanelField003c(int nMode);
extern int Ov002_GetPanelField018c(void);
extern void Ov002_ClearCurrentCaption(void);

/* Follow-up handler an element hands over to when its line finishes.
 *
 * Nothing runs at all while the global hold is set. The element takes the other
 * entries over again if it had released them, and then the step depends on how
 * far the hand-over has got: step 1 opens the choice, using the owner's own
 * parameters when the game state asks for it and the plain ones otherwise;
 * step 2 reads the answer back and either says the closing line or drops
 * straight out; step 3 waits for the transition and restores the step it had
 * saved; step 4 puts everything back. Always returns zero.
 */
int Ov002_ElementChoiceStep(char *pElement)
{
    char *pOwner;
    int nRes;
    int nA;
    int nB;

    pOwner = *(char **)(pElement + 8);

    if (data_0204be04 != 0) {
        return 0;
    }

    if ((*(u8 *)(pElement + 0x1b5) & 2) != 0) {
        Ov002_SetRosterHighlight(pElement, QueryActiveStateOrDelegate(), 1);
    }

    switch (*(u8 *)(pElement + 0x1b6)) {
    case 1:
        if (Ov002_Hud_IsPanelOpen() != 0 || Ov002_GetRootField8b68Alt() != 0) {
            Ov002_SetRosterHighlight(pElement, QueryActiveStateOrDelegate(), 0);
            *(u8 *)(pElement + 0x1b6) = 0;
            func_02020878(1);
            if (*(signed char *)(pElement + 0x1bb) != 0) {
                Ov002_SetLeaveRequest(0);
            }
            return 0;
        }

        if (Ov002_GetPhaseWord() == 5) {
            Ov002_SetSessionActive(1, (u8)(Ov002_GetRootField8b41() & ~0xb));
        } else {
            Ov002_SetSessionActive(1, (u8)(Ov002_GetRootField8b41() & ~0xa));
        }

        if (GameState_IsFlagSet(0x2085) != 0) {
            Ov002_SubmitRequestRecord(*(int *)(pOwner + 0x70),
                                *(int *)(pOwner + 0x78),
                                *(int *)(pOwner + 0x7c), 1);
            *(u8 *)(pElement + 0x1b6) = 2;
        } else {
            Ov002_SubmitRequestRecord(*(int *)(pOwner + 0x6c), 0, 0, 0);
            *(u8 *)(pElement + 0x1b7) = 4;
            *(u8 *)(pElement + 0x1b6) = 3;
            if (*(signed char *)(pElement + 0x1bb) != 0) {
                Ov002_SetLeaveRequest(0);
            }
        }

        if (Ov002_GetPhaseWord() == 1 || Ov002_GetPhaseWord() == 5) {
            nA = func_ov022_02083f0c();
            func_ov022_02086818(func_ov022_02083f5c(), 0);
            Ov002_SetOrClearFlag200(nA, 1);
            Ov002_Camera_SetMode(nA, 1, 0);
            if (Ov002_GetPhaseWord() == 5) {
                Ov002_SetOrClearFlag200(func_ov022_02083f40(), 1);
            }
        }
        break;

    case 2:
        nRes = Ov002_GetPanelRequestBlock();
        if (nRes < 0) {
            break;
        }
        if (nRes == 0) {
            if (*(signed char *)(pElement + 0x1bb) != 0) {
                Ov002_StreamFormattedLine(data_ov002_0207f480, pElement + 0x1bb);
                if (Ov002_GetPhaseWord() == 5) {
                    Ov002_SetRootField8b41((u8)(Ov002_GetRootField8b41() & ~0xb));
                } else {
                    Ov002_SetRootField8b41((u8)(Ov002_GetRootField8b41() & ~0xa));
                }
                Ov002_SetRootField8b40();
            } else if (Session_GetLocalPlayerIndex() == 0) {
                Ov002_BeginSessionTeardown(0);
            }
            *(u8 *)(pElement + 0x1b6) = 0;
            Ov002_SetSessionBusy(1);
        } else {
            Ov002_SetPanelField003c(0);
            *(u8 *)(pElement + 0x1b7) = 4;
            *(u8 *)(pElement + 0x1b6) = 3;
            if (*(signed char *)(pElement + 0x1bb) != 0) {
                Ov002_SetLeaveRequest(0);
            }
        }
        break;

    case 3:
        if (Ov002_GetPanelField018c() != 0) {
            Ov002_ClearCurrentCaption();
            *(u8 *)(pElement + 0x1b6) = *(u8 *)(pElement + 0x1b7);
            *(u8 *)(pElement + 0x1b7) = 0;
        }
        break;

    case 4:
        func_02020878(1);
        Ov002_SetRosterHighlight(pElement, QueryActiveStateOrDelegate(), 0);
        Ov002_SetSessionActive(0, 0);
        *(u8 *)(pElement + 0x1b6) = 0;

        if (Ov002_GetPhaseWord() == 1 || Ov002_GetPhaseWord() == 5) {
            nA = func_ov022_02083f0c();
            nB = func_ov022_02083f5c();
            Ov002_Camera_SetMode(nA, 0, 0);
            Ov002_SetOrClearFlag200(nA, 0);
            func_ov022_02086818(nB, 1);
            if (Ov002_GetPhaseWord() == 5) {
                Ov002_SetOrClearFlag200(func_ov022_02083f40(), 0);
            }
        }
        break;
    }

    return 0;
}
