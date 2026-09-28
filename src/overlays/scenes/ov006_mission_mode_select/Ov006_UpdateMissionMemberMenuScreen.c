/* Ov006_UpdateMissionMemberMenuScreen -- per-frame update of the Mission Mode member menu screen, ov006.
 *
 * Reads the cursor entry and the pad state, then bails out to the video-scene state
 * function when the menu has been confirmed or the cursor is 0xff, clearing the
 * context's parameters-ready flag on the way out.
 *
 * Otherwise it refreshes the four member rows from the mission tables, resolves the
 * selection for the cursor row, and -- while the sub-state is 5 and an entry is live --
 * runs the member-selection input pass over a saved copy of the cursor row, restoring
 * the row afterwards so only the arm-cursor request survives.
 *
 * It then decides whether the "all members ready" slot is shown: every visible row must
 * carry its ready flag, the ready count must equal the polled key count, and no two
 * visible rows may share a member id.
 *
 * After committing the title mode, model pose, slot visibility and cursor selection, the
 * sub-states 4-6 redraw the text layers: the prompt line, the resolved and cursor name
 * lines, the two label columns, the four per-slot labels and the footer prompt.
 *
 * Finally the local rows are written back to the shared context and the next state
 * function is returned (0 to stay, or the menu-state entry point after a confirm). */

/* One mission-menu row. Eight bytes, so the ROM indexes it with `lsl #3`.
 * The same layout backs the twin loop in ov008; the offsets are what the
 * disassembly pins, the names what the uses show.
 */

#include "nitro/types.h"

typedef struct {
    u16 id;          /* +0x00  entry id                                    */
    u8 slotUsed;     /* +0x02  row occupied; gates the cues and the counter */
    u8 readyFlag;    /* +0x03  member is ready; the 0x2e / 0x2f cue pair    */
    s8 memberId;     /* +0x04  loaded signed, compared as u8 against the ctx */
    s8 sprite;       /* +0x05  not read by this function                   */
    u8 value6;       /* +0x06  not read here; named to match the Ghidra type */
    u8 pad_7;        /* +0x07  padding to the 8-byte stride                */
} MissionMenuRow;

typedef struct {
    void *sceneObject;
    u16 inputHeader[13];
    u8 pad_1e[2];
    int sessionReady;
    int parametersReady;
    int singleRowMode;
    int menuState;
    u8 optionMask;
    u8 messageStateFlag;
    u16 messageId;
    u16 messageTimer;
    u8 pad_36[2];
    u8 selection[8];   /* Ov006MissionMenuSelectionState in the Ghidra model */
    MissionMenuRow rows[4];
    u8 resource[0x0d];
    u8 rowDataReady;
} MissionMenuContext;

extern MissionMenuContext *data_ov006_02056660;
extern u16 data_0204c190;
extern u8 data_ov006_020561d0[];

extern void func_020362ec(void *image);
extern int PlaySound(int bank, int sound);  /* PlaySound */
extern u16 Ov006_MissionGetCursorEntry(void);  /* Ov006_MissionGetCursorEntry */
extern int Ov006_GetMissionMenuSelection(void);  /* Ov006_GetMissionMenuSelection */
extern int Ov006_CountPlayers(void);  /* Ov006_CountPlayers */
extern int Ov006_Link_Poll(void);
extern void Ov006_SetPendingInput(int memberId);  /* Ov006_SetPendingInput */
extern void Ov006_GetMissionRowInfo(int row, MissionMenuRow *out);  /* Ov006_GetMissionRowInfo */
extern int Ov006_MissionIsEntryActive(void);  /* Ov006_MissionIsEntryActive */
extern void Ov006_MissionArmCursorRequest(u16 *row);  /* Ov006_MissionArmCursorRequest */
extern void Ov006_BlankScreensAndTeardownText(void);  /* Ov006_BlankScreensAndTeardownText */
extern void Ov006_MissionApplyParameterRow(int selection);  /* Ov006_MissionApplyParameterRow */
extern int Ov006_ResolveMissionSelection(int memberId);  /* Ov006_ResolveMissionSelection */
extern int Ov006_CanConfirmMissionMenu(void);  /* Ov006_CanConfirmMissionMenu */
extern void Ov006_MemberMenuNextStateNoOp(void);
extern void Ov006_MissionInitVideoScene(void);  /* Ov006_MissionInitVideoScene */
extern int Ov006_UpdateMissionMemberSelectionInput(MissionMenuRow *rows, int *resolvedSelectionOut);  /* Ov006_UpdateMissionMemberSelectionInput */
extern int Ov006_MissionScene_IsFlagSet(void);
extern int Ov006_MissionScene_GetState(void);
extern int Ov006_SetTitleWord(int slot, int flag);  /* Ov006_SetTitleWord */
extern int Ov006_RequestMenuState(unsigned int state, int animate, int completion);  /* Ov006_RequestMenuState */
extern void Ov006_SetMissionCursorSelection(int selection);
extern int Ov006_SetTitleMode(unsigned int mode);
extern int Ov006_SetMissionRowSlotValue(int slot, int value, int visible);
extern int Ov006_MissionSetModelPose(int pose);  /* Ov002_BeginTextCrawl */
extern void Ov006_MissionSetSlotVisible(int visible);  /* Ov006_MissionSetSlotVisible */
extern void Ov006_ResetTextLayers(void);  /* Ov006_ResetTextLayers */
extern void *Ov006_GetVarRecordByIndex(void *resource, int index);  /* GetVarRecordByIndex */
extern void Ov006_MissionDrawTextRunFwd(void *text, int x, int y, int style, int layer, /* Ov006_MissionDrawTextRunFwd */
                            int align, int visible);
extern void Ov006_FlushTextLayers(void);  /* Ov006_FlushTextLayers */

void *Ov006_UpdateMissionMemberMenuScreen(void)
{
    MissionMenuRow rows[4];
    int resolvedSelection;
    MissionMenuRow saved;
    u8 labels[8];
    MissionMenuRow probeC;
    MissionMenuRow probeD;
    MissionMenuRow probe;
    MissionMenuRow probeB;
    MissionMenuRow probeA;
    void *result;
    int canConfirm;
    unsigned int cursorEntry;
    unsigned int pollKeys;
    unsigned int messageId;
    unsigned int allSame;
    int slotVisible;
    u8 i;
    u8 j;
    u8 count;
    u8 visibleSlot;
    int unique;
    int x;
    int y;
    int stateCode;
    int paramSel;
    void *record;
    u8 *labelsHi;
    MissionMenuRow *rowPtr;

    result = 0;
    cursorEntry = Ov006_MissionGetCursorEntry();
    pollKeys = (unsigned int)Ov006_CountPlayers();
    allSame = 0;
    slotVisible = 0;
    resolvedSelection = 0;
    func_020362ec(data_ov006_02056660->inputHeader);

    if (Ov006_CanConfirmMissionMenu() != 0 || cursorEntry == 0xff) {
        Ov006_BlankScreensAndTeardownText();
        data_ov006_02056660->rowDataReady = 0;
        return (void *)Ov006_MissionInitVideoScene;
    }

    i = 0;
    do {
        Ov006_GetMissionRowInfo(i, &rows[i]);
        i++;
    } while (i < 4);

    canConfirm = Ov006_CanConfirmMissionMenu();
    resolvedSelection = Ov006_ResolveMissionSelection(rows[cursorEntry].memberId);
    if (Ov006_MissionScene_IsFlagSet() != 0 && canConfirm == 0 &&
        Ov006_MissionScene_GetState() == 5 && Ov006_MissionIsEntryActive() != 0) {
        saved = rows[cursorEntry];
        if (Ov006_UpdateMissionMemberSelectionInput(rows, &resolvedSelection) != 0) {
            rows[cursorEntry].id++;
        }
        Ov006_MissionArmCursorRequest((u16 *)&rows[cursorEntry]);
        rows[cursorEntry] = saved;
    }

    if (Ov006_MissionScene_IsFlagSet() != 0 &&
        data_ov006_02056660->sessionReady != 0) {
        count = 0;
        i = 0;
        do {
            Ov006_GetMissionRowInfo(i, &probe);
            if (probe.slotUsed != 0) {
                if (probe.readyFlag == 0) {
                    allSame = 0;
                    goto have_flag;
                }
                count++;
            }
            i++;
        } while (i < 4);
        if (count != (unsigned int)Ov006_CountPlayers()) {
            allSame = 0;
        } else {
            allSame = 1;
        }

have_flag:
        if (allSame != 0) {
            if (data_ov006_02056660->singleRowMode != 0) {
                unique = 1;
            } else {
                i = 0;
                do {
                    j = (u8)(i + 1);
                    while (j < 4) {
                        Ov006_GetMissionRowInfo(i, &probeA);
                        Ov006_GetMissionRowInfo(j, &probeB);
                        if (probeA.slotUsed != 0 && probeB.slotUsed != 0 &&
                            probeA.memberId == probeB.memberId) {
                            unique = 0;
                            goto have_unique;
                        }
                        j++;
                    }
                    i++;
                } while (i < 4);
                unique = 1;
            }
have_unique:
            if (unique != 0) {
                slotVisible = 1;
                if ((data_0204c190 & 8) != 0) {
                    Ov006_SetPendingInput(rows[0].memberId);
                }
            }
        }
    }

    Ov006_SetTitleMode(pollKeys);
    Ov006_MissionSetModelPose(rows[cursorEntry].memberId);
    Ov006_MissionSetSlotVisible(slotVisible);
    Ov006_SetMissionCursorSelection(Ov006_GetMissionMenuSelection());

    if (Ov006_MissionScene_GetState() == 5 &&
        (data_ov006_02056660->parametersReady == 0 ||
         rows[cursorEntry].memberId !=
             data_ov006_02056660->rows[cursorEntry].memberId)) {
        if (resolvedSelection != 0) {
            paramSel = rows[cursorEntry].memberId;
        } else {
            paramSel = 0x13;
        }
        Ov006_MissionApplyParameterRow(paramSel);
    }

    /* Push the four rows to the on-screen slots and play the change cues.
     *
     * visibleSlot counts only rows that are in use, so the display packs the live
     * rows upwards while i still walks the fixed four-entry table. Each row reports
     * its occupancy first, then its member and ready state.
     *
     * The cues compare against the shared context, i.e. the state as of the previous
     * frame, so they fire once on the frame a value actually changes: cue 0 when the
     * cursor row's member changes, 0x2e when a row becomes ready and 0x2f when it
     * stops being ready. Rows that are not in use stay silent.
     */
    visibleSlot = 0;
    i = 0;
    do {
        Ov006_SetTitleWord(visibleSlot, rows[i].slotUsed);
        rowPtr = &rows[i];
        Ov006_SetMissionRowSlotValue(visibleSlot, (u16)rowPtr->memberId, rowPtr->readyFlag);
        if (rows[i].slotUsed != 0) {
            if (i == cursorEntry &&
                (u8)rows[i].memberId != (u8)data_ov006_02056660->rows[i].memberId) {
                PlaySound(0, 0);
            }
            if (rows[i].readyFlag != data_ov006_02056660->rows[i].readyFlag) {
                if (rows[i].readyFlag != 0) {
                    PlaySound(0, 0x2e);
                } else {
                    PlaySound(0, 0x2f);
                }
            }
        }
        if (rows[i].slotUsed != 0) {
            visibleSlot++;
        }
        i++;
    } while (i < 4);

    if (Ov006_Link_Poll() == 3) {
        PlaySound(0, 1);
        Ov006_RequestMenuState(7, 1, 0);
        result = (void *)Ov006_MemberMenuNextStateNoOp;
    }

    stateCode = Ov006_MissionScene_GetState();
    if (!(stateCode != 4 && stateCode != 5 && stateCode != 6)) {
        labels[3] = data_ov006_020561d0[6];
        labels[4] = data_ov006_020561d0[7];
        labels[5] = data_ov006_020561d0[8];
        labels[6] = data_ov006_020561d0[9];
        labels[0] = data_ov006_020561d0[0];
        labels[1] = data_ov006_020561d0[1];
        labels[2] = data_ov006_020561d0[2];
        Ov006_ResetTextLayers();

        if (data_ov006_02056660->sessionReady != 0) {
            Ov006_GetMissionRowInfo((int)cursorEntry, &probeC);
            if (probeC.readyFlag == 0 || rows[cursorEntry].readyFlag == 0) {
                messageId = 0x33;
            } else if (allSame == 0) {
                messageId = 0x34;
            } else {
                messageId = 0x37;
            }
        } else if (rows[cursorEntry].readyFlag == 0) {
            data_ov006_02056660->messageId = 0x35;
            data_ov006_02056660->messageTimer = 0;
            messageId = 0x33;
        } else {
            data_ov006_02056660->messageTimer++;
            if (data_ov006_02056660->messageTimer > 0x3c) {
                data_ov006_02056660->messageTimer = 0;
                if (data_ov006_02056660->messageId == 0x34) {
                    data_ov006_02056660->messageId = 0x35;
                } else {
                    data_ov006_02056660->messageId = 0x34;
                }
            }
            messageId = (unsigned int)(data_ov006_02056660->messageId & 0xff);
        }

        record = Ov006_GetVarRecordByIndex(data_ov006_02056660->resource, (int)messageId);
        Ov006_MissionDrawTextRunFwd(record, 0xfa, 2, (u8)1, 1, 1, 1);

        if (resolvedSelection != 0) {
            record = Ov006_GetVarRecordByIndex(data_ov006_02056660->resource,
                                     rows[Ov006_MissionGetCursorEntry()].memberId + 0xb);
        } else {
            record = Ov006_GetVarRecordByIndex(data_ov006_02056660->resource, 0x1e);
        }
        Ov006_MissionDrawTextRunFwd(record, 0x26, 0x1c, (u8)1, 1, 2, 1);

        record = Ov006_GetVarRecordByIndex(data_ov006_02056660->resource,
                                 rows[Ov006_MissionGetCursorEntry()].memberId + 0x1f);
        Ov006_MissionDrawTextRunFwd(record, 0x80, 0x1c, (u8)1, 1, 2, 1);

        i = 0;
        labelsHi = &labels[3];
        do {
            record = Ov006_GetVarRecordByIndex(data_ov006_02056660->resource,
                                     labelsHi[i]);
            Ov006_MissionDrawTextRunFwd(record, 0x87, i * 0x10 + 0x38, (u8)1, 1, 1, 1);
            i++;
        } while (i < 4);

        i = 0;
        do {
            record = Ov006_GetVarRecordByIndex(data_ov006_02056660->resource,
                                     labels[i]);
            Ov006_MissionDrawTextRunFwd(record, 0xe4, i * 0x10 + 0x38, (u8)1, 1, 1, 1);
            i++;
        } while (i < 3);

        i = 0;
        do {
            switch (i) {
            case 0:
                x = 0x44;
                y = 0x9a;
                break;
            case 1:
                x = 0xc4;
                y = 0x9a;
                break;
            case 2:
                x = 0x44;
                y = 0xb0;
                break;
            case 3:
                x = 0xc4;
                y = 0xb0;
                break;
            default:
                x = 0;
                y = 0;
                break;
            }
            if (rows[i].slotUsed != 0 || i == Ov006_MissionGetCursorEntry()) {
                if (Ov006_ResolveMissionSelection(rows[i].memberId) != 0) {
                    record = Ov006_GetVarRecordByIndex(
                        data_ov006_02056660->resource,
                        rows[i].memberId + 0xb);
                } else {
                    record = Ov006_GetVarRecordByIndex(
                        data_ov006_02056660->resource, 0x1e);
                }
                Ov006_MissionDrawTextRunFwd(record, x, y, (u8)1, 1, 2, 1);
            }
            i++;
        } while (i < 4);

        if (data_ov006_02056660->sessionReady != 0) {
            Ov006_GetMissionRowInfo((int)cursorEntry, &probeD);
            if (probeD.readyFlag == 0 || rows[cursorEntry].readyFlag == 0) {
                messageId = 0x38;
            } else if (allSame == 0) {
                messageId = 0x39;
            } else {
                messageId = 0x3a;
            }
        } else if (rows[cursorEntry].readyFlag == 0) {
            messageId = 0x38;
        } else {
            messageId = 0x39;
        }

        record = Ov006_GetVarRecordByIndex(data_ov006_02056660->resource, (int)messageId);
        Ov006_MissionDrawTextRunFwd(record, 0xa, 0xb4, (u8)1, 1, 0, 0);
        Ov006_FlushTextLayers();
    }

    i = 0;
    do {
        data_ov006_02056660->rows[i] = rows[i];
        i++;
    } while (i < 4);

    return result;
}
