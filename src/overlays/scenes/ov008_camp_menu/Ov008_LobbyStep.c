/* Ov008_LobbyStep -- Ov008_LobbyStep: one frame of the mission
 * lobby's member panel.  The four member rows are read (0207b960), the
 * local player's (0207b138) cursor resolved from its icon (0207bda4) and,
 * while the session is joined (02081694) by a guest (0207be38 == 0) in
 * state 5 (020816c0) with input allowed (0207ba08), the cursor moves
 * (0207d888 on a saved copy of the row, id + 1 when it moved, 0207ba68).
 * A guest then commits its icon (0207b908) when its row is set and either
 * the lobby is locked (+0x28) or no two set rows share an icon; the host
 * commits the local index's icon on button 1.  The panel updates
 * (020818a0, 020819a8 with the icon, 02081b74, 0208187c with 0207b7b4) and
 * in state 5 the icon list (0207bcdc: 0x13 without a cursor) refreshes when
 * the lobby is unlocked (+0x24) or the icon changed against the stored row
 * (+0x40 + 8 * i).  Each set row shows its slot (02081708, 020818e0) with
 * sounds for an icon change of the local row and for a flag change
 * (0x2e / 0x2f); a lobby result of 3 (0207b8f0) requests state 7 and returns
 * the next step 0207d5cc.  In states 4 .. 6 the text layers are rebuilt
 * (02081da0 .. 02081e08): the title (0x36 host / 0x33 guest), the cursor
 * text (0x1e or icon + 0xb), the icon name (+ 0x1f), the four column and
 * three row captions of 0208fc8c, each set (or local) row's icon text at
 * (0x44 / 0xc4, 0x9a / 0xb0) and the footer (0x3b / 0x38).  The rows are
 * stored back to +0x40.  Codegen: the next step, the host flag and the
 * cursor (address taken) are spilled; loop counters are u8; the saved row
 * is a halfword struct copy; the caption tables are two struct copies
 * (columns first); the pair scan is two nested for loops with a flag;
 * hoisted constants (0, 0x2e, 1, 0x87, 0xe4, 0x44, 0x9a, 2) sit in
 * callee-saved registers.  The 020818e0 prototype takes the icon as u16
 * (the ov006 twin's form): mwcc emits no narrowing for it, but the halfword
 * parameter is what schedules the slot copy after the row loads.
 */

#include "nitro/types.h"

#define MEMBER_COUNT   4
#define STATE_LOBBY    5
#define ICON_NONE      0x13
#define TEXT_CURSOR_NONE 0x1e
#define TEXT_ICON_BASE 0xb
#define TEXT_NAME_BASE 0x1f
#define SOUND_FLAG_ON  0x2e
#define SOUND_FLAG_OFF 0x2f

typedef void (*Ov008LobbyStep)(void);

typedef struct MissionMenuRow {
    u16 id;
    u8  flags2;
    u8  flags3;
    s8  icon;
    s8  sprite;
    u8  field6;
    u8  pad7;
} MissionMenuRow;

typedef struct Ov008LobbyColumnTexts {
    u8 aText[4];
} Ov008LobbyColumnTexts;

typedef struct Ov008LobbyRowTexts {
    u8 aText[3];
} Ov008LobbyRowTexts;

typedef struct Ov008LobbyCaptions {
    Ov008LobbyRowTexts row;    /* 0x00 */
    u8 pad_03[3];
    Ov008LobbyColumnTexts col; /* 0x06 */
} Ov008LobbyCaptions;

typedef struct MissionMenuContext {
    void *sceneObject;        /* 0x00 */
    u16  inputHeader[13];     /* 0x04 */
    u8   pad_1e[6];
    int  bUnlocked;           /* 0x24 */
    int  bLocked;             /* 0x28 */
    u8   pad_2c[0x40 - 0x2c];
    MissionMenuRow aPlayer[MEMBER_COUNT]; /* 0x40 */
    u8   records[0xc];        /* 0x60 */
} MissionMenuContext;

extern MissionMenuContext *data_ov008_02090fa0;
extern u16 data_0204c190;
extern const Ov008LobbyCaptions data_ov008_0208fc8c;
extern void  Ov008_LobbyNextStepNoOp(void);                                  /* next lobby step */
extern u16   Ov008_GetLocalPlayerIndex(void);                                  /* local member index */
extern int   Ov008_CountPlayers(void);
extern void  func_020362ec(u16 *pHeader);
extern void  Ov008_GetMissionRowInfo(int nRow, MissionMenuRow *pOut);
extern int   Ov008_CanConfirmMissionMenu(void);                                  /* is host */
extern int   Ov008_ResolveMissionSelection(int nIcon);                             /* cursor of an icon */
extern int   Ov008_MissionScene_IsFlagSet(void);                                  /* session joined */
extern int   Ov008_MissionScene_GetState(void);                                  /* lobby state */
extern int   Ov008_MissionIsEntryActive(void);                                  /* input allowed */
extern int   Ov008_UpdateMissionMemberSelectionInput(MissionMenuRow *aRows, int *pnCursor);  /* move the cursor */
extern void  Ov008_MissionArmCursorRequest(MissionMenuRow *pRow);
extern void  Ov008_Link_RequestLeave(int nIcon);                             /* commit the icon */
extern u32   Session_GetLocalPlayerIndex(void);                                        /* Session_GetLocalPlayerIndex */
extern void  Ov008_MissionScene_SetMode(int nValue);                            /* Ov008_Fn_18a0 */
extern void  Ov008_MissionSetModelPose(int nIcon);
extern void  Ov008_MissionSetSlotVisible(int bOn);
extern int   Ov008_GetMissionMenuSelection(void);
extern void  Ov008_SetMissionCursorSelection(int nSelection);
extern void  Ov008_MissionApplyParameterRow(int nIcon);                             /* refresh the icon list */
extern void  Ov008_SetTitleWord(int nSlot, int bSet);
extern void  Ov008_SetMissionRowSlotValue(int nSlot, int nIcon, int bVisible);
extern void  PlaySound(int nBank, int nSound);                       /* PlaySound */
extern int   Ov008_Link_Poll(void);                                  /* lobby result */
extern void  Ov008_RequestMenuState(int nState, int bAnimate, int nValue);  /* Ov008_RequestMenuState */
extern void  Ov008_ResetTextLayers(void);                                  /* Ov008_ResetTextLayers */
extern void *Ov008_GetVarRecordByIndex(void *pRecords, int nIndex);            /* GetVarRecordByIndex */
extern void  Ov008_ForwardSevenArgs(void *pText, int nX, int nY, int nA, int nB, int nC, int nD); /* Ov008_ForwardSevenArgs */
extern void  Ov008_FlushTextLayers(void);                                  /* Ov008_FlushTextLayers */

Ov008LobbyStep Ov008_LobbyStep(void)
{
    MissionMenuRow aRow[MEMBER_COUNT];
    int nCursor;
    MissionMenuRow saved;
    MissionMenuRow rowLocal;
    Ov008LobbyColumnTexts col;
    Ov008LobbyRowTexts row;
    MissionMenuRow rowB;
    MissionMenuRow rowA;
    Ov008LobbyStep pfnNext;
    int bHost;
    u16 nLocal;
    int nSession;
    u8 i;
    u8 a;
    u8 b;
    u8 nSlot;
    int bReady;
    void *pText;
    int nX;
    int nY;
    int nState;
    int nIcon;
    s8 nIcon8;

    pfnNext = 0;
    nLocal = Ov008_GetLocalPlayerIndex();
    nSession = Ov008_CountPlayers();
    nCursor = 0;
    func_020362ec(data_ov008_02090fa0->inputHeader);
    for (i = 0; i < MEMBER_COUNT; i++) {
        Ov008_GetMissionRowInfo(i, &aRow[i]);
    }
    bHost = Ov008_CanConfirmMissionMenu();
    nCursor = Ov008_ResolveMissionSelection(aRow[nLocal].icon);
    if (Ov008_MissionScene_IsFlagSet() != 0 && bHost == 0 && Ov008_MissionScene_GetState() == STATE_LOBBY && Ov008_MissionIsEntryActive()) {
        saved = aRow[nLocal];
        if (Ov008_UpdateMissionMemberSelectionInput(aRow, &nCursor) != 0) {
            aRow[nLocal].id++;
        }
        Ov008_MissionArmCursorRequest(&aRow[nLocal]);
        aRow[nLocal] = saved;
    }
    if (Ov008_MissionScene_IsFlagSet() != 0) {
        if (bHost == 0) {
            Ov008_GetMissionRowInfo(nLocal, &rowLocal);
            if (rowLocal.flags2 != 0 && rowLocal.flags3 != 0) {
                if (data_ov008_02090fa0->bLocked != 0) {
                    bReady = 1;
                } else {
                    for (a = 0; a < MEMBER_COUNT; a++) {
                        for (b = a + 1; b < MEMBER_COUNT; b++) {
                            Ov008_GetMissionRowInfo(a, &rowA);
                            Ov008_GetMissionRowInfo(b, &rowB);
                            if (rowA.flags2 != 0 && rowB.flags2 != 0 && rowA.icon == rowB.icon) {
                                bReady = 0;
                                goto checked;
                            }
                        }
                    }
                    bReady = 1;
                }
checked:
                if (bReady) {
                    Ov008_Link_RequestLeave(aRow[nLocal].icon);
                }
            }
        } else {
            nLocal = Session_GetLocalPlayerIndex();
            if (data_0204c190 & 1) {
                Ov008_Link_RequestLeave(aRow[nLocal].icon);
            }
        }
    }
    Ov008_MissionScene_SetMode(nSession);
    Ov008_MissionSetModelPose(aRow[nLocal].icon);
    Ov008_MissionSetSlotVisible(0);
    Ov008_SetMissionCursorSelection(Ov008_GetMissionMenuSelection());
    if (Ov008_MissionScene_GetState() == STATE_LOBBY && (data_ov008_02090fa0->bUnlocked == 0 || aRow[nLocal].icon != data_ov008_02090fa0->aPlayer[nLocal].icon)) {
        Ov008_MissionApplyParameterRow(nCursor != 0 ? aRow[nLocal].icon : ICON_NONE);
    }
    nSlot = 0;
    for (i = 0; i < MEMBER_COUNT; i++) {
        Ov008_SetTitleWord(nSlot, aRow[i].flags2);
        Ov008_SetMissionRowSlotValue(nSlot, (u16)aRow[i].icon, aRow[i].flags3);
        if (aRow[i].flags2 != 0) {
            if (i == nLocal && (u8)aRow[i].icon != (u8)data_ov008_02090fa0->aPlayer[i].icon) {
                PlaySound(0, 0);
            }
            if (aRow[i].flags3 != data_ov008_02090fa0->aPlayer[i].flags3) {
                if (aRow[i].flags3 != 0) {
                    PlaySound(0, SOUND_FLAG_ON);
                } else {
                    PlaySound(0, SOUND_FLAG_OFF);
                }
            }
        }
        if (aRow[i].flags2 != 0) {
            nSlot++;
        }
    }
    if (Ov008_Link_Poll() == 3) {
        Ov008_RequestMenuState(7, 1, 0);
        pfnNext = Ov008_LobbyNextStepNoOp;
    }
    nState = Ov008_MissionScene_GetState();
    if (!(nState != 4 && nState != 5 && nState != 6)) {
        col = data_ov008_0208fc8c.col;
        row = data_ov008_0208fc8c.row;
        Ov008_ResetTextLayers();
        Ov008_ForwardSevenArgs(Ov008_GetVarRecordByIndex(data_ov008_02090fa0->records, bHost != 0 ? 0x36 : 0x33), 0xfa, 2, 1, 1, 1, 1);
        if (nCursor != 0) {
            pText = Ov008_GetVarRecordByIndex(data_ov008_02090fa0->records, aRow[Ov008_GetLocalPlayerIndex()].icon + TEXT_ICON_BASE);
        } else {
            pText = Ov008_GetVarRecordByIndex(data_ov008_02090fa0->records, TEXT_CURSOR_NONE);
        }
        Ov008_ForwardSevenArgs(pText, 0x26, 0x1c, 1, 1, 2, 1);
        Ov008_ForwardSevenArgs(Ov008_GetVarRecordByIndex(data_ov008_02090fa0->records, aRow[Ov008_GetLocalPlayerIndex()].icon + TEXT_NAME_BASE), 0x80, 0x1c, 1, 1, 2, 1);
        for (i = 0; i < 4; i++) {
            Ov008_ForwardSevenArgs(Ov008_GetVarRecordByIndex(data_ov008_02090fa0->records, col.aText[i]), 0x87, i * 0x10 + 0x38, 1, 1, 1, 1);
        }
        for (i = 0; i < 3; i++) {
            Ov008_ForwardSevenArgs(Ov008_GetVarRecordByIndex(data_ov008_02090fa0->records, row.aText[i]), 0xe4, i * 0x10 + 0x38, 1, 1, 1, 1);
        }
        for (i = 0; i < MEMBER_COUNT; i++) {
            switch (i) {
            case 0:
                nX = 0x44;
                nY = 0x9a;
                break;
            case 1:
                nX = 0xc4;
                nY = 0x9a;
                break;
            case 2:
                nX = 0x44;
                nY = 0xb0;
                break;
            case 3:
                nX = 0xc4;
                nY = 0xb0;
                break;
            default:
                nX = 0;
                nY = 0;
                break;
            }
            if (aRow[i].flags2 != 0 || i == Ov008_GetLocalPlayerIndex()) {
                if (Ov008_ResolveMissionSelection(aRow[i].icon) != 0) {
                    pText = Ov008_GetVarRecordByIndex(data_ov008_02090fa0->records, aRow[i].icon + TEXT_ICON_BASE);
                } else {
                    pText = Ov008_GetVarRecordByIndex(data_ov008_02090fa0->records, TEXT_CURSOR_NONE);
                }
                Ov008_ForwardSevenArgs(pText, nX, nY, 1, 1, 2, 1);
            }
        }
        Ov008_ForwardSevenArgs(Ov008_GetVarRecordByIndex(data_ov008_02090fa0->records, bHost != 0 ? 0x3b : 0x38), 10, 0xb4, 1, 1, 0, 0);
        Ov008_FlushTextLayers();
    }
    for (i = 0; i < MEMBER_COUNT; i++) {
        data_ov008_02090fa0->aPlayer[i] = aRow[i];
    }
    return pfnNext;
}
