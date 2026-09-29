/* Ov006_CommitMissionModeUiSlots -- commit the Mission Mode UI slot set for the
 * current sub-state (Mission Mode character-select screen, ov006).
 *
 * States 0-1 place the active row marker and its header slot; states 2-3 refresh
 * the header row and, when the secondary group is visible, its three extra slots;
 * states 4-6 rebuild the whole mission list on the sub screen and the entry
 * markers on the main screen; states 7-14 commit nothing extra. Both slot sets
 * are flushed on every path.
 *
 * Slot-id table: 0x95C4..0x9603 is one contiguous run of 16 ids. The state 4-6
 * paths walk it as the disjoint windows headerSlotIds[2], rowSlotIds[4],
 * secondarySlotIds[3] and panelSlotIds[7]; the state 0-1 and 2-3 paths instead
 * walk a 4-entry window starting at 0x95D8, which straddles rowSlotIds[3] and
 * secondarySlotIds[0..2]. The overlap is in the original code, not a mis-typed
 * array. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct {
    int x;
    int y;
} UiLayoutPos;

typedef struct {
    u8 reserved_0000[0x54];
    u8 subScreenSlotSet[0x4a38];
    u8 mainScreenSlotSet[0x4a68];
    int currentState;
    u8 reserved_94f8[0x10];
    int entryCount;
    s8 selectedEntry;
    u8 supplementalSlotsVisible;
    u8 reserved_950e[2];
    int entryValues[5];
    int entryHandles[4];
    int entryFlags[4];
    u8 reserved_9544[0x68];
    u8 activeRow;
    u8 secondaryGroupVisible;
    u8 reserved_95ae[0x16];
    int headerSlotIds[2];
    int rowSlotIds[4];
    int secondarySlotIds[3];
    int panelSlotIds[7];
    int entryOverlaySlotIds[4];
    u8 reserved_9614[0xc4];
    int overlayHeaderSlotIds[2];
    int selectionMarkerSlotId;
    int emptyEntrySlotIds[4];
    int disabledEntrySlotIds[4];
    int enabledEntrySlotIds[4];
    int categoryMarkerSlotIds[19];
    u8 reserved_9760[0x98];
} Ov006MissionModeUiView;

extern Ov006MissionModeUiView *data_ov008_02090fa4;

extern void Slot_SetPosition(void *slots, int slotId, UiLayoutPos *position);
extern int Ov008_IsMissionSelectionEnabled(int selection);

#define PANEL_MAIN(view) ((void *)(view)->mainScreenSlotSet)
#define PANEL_SUB(view) ((void *)(view)->subScreenSlotSet)

/* MWCC folds the two adds that build mainScreenSlotSet into the view register,
 * which uses one scratch register fewer than the original. Re-casting the 0x28c
 * intermediate at the point of use blocks the fold and restores the original
 * allocation. Only the two call sites below need it. */
#define PANEL_MAIN_SPLIT(view) ((u8 *)((u8 *)(view) + 0x28c) + 0x4800)

void Ov008_CommitMissionModeUiSlots(void)
{
    Ov006MissionModeUiView **contextSlot;
    Ov006MissionModeUiView *context;
    UiLayoutPos position;
    u32 index;
    int slotId;
    int validity;

    context = data_ov008_02090fa4;
    if (context == 0) {
        return;
    }

    switch (context->currentState) {
    case 0:
    case 1:
        if (context->selectedEntry >= 0) {
            Slot_ForwardToEntry(PANEL_MAIN(context), context->headerSlotIds[1],
                          (u16)context->selectedEntry);
        }

        {
            u32 loopIndex = 0;
            int loopSlotId;
            do {
                context = data_ov008_02090fa4;
                if ((u8)context->activeRow - 1 == loopIndex) {
                    position.x = 0x80000;
                    position.y = ((context->activeRow - 1) * 0x18 + 0x28) * 0x1000;
                    loopSlotId = context->rowSlotIds[2];
                    Slot_SetPosition(PANEL_MAIN(context), loopSlotId, &position);
                    Obj_CommitAlphaBlend(PANEL_MAIN(data_ov008_02090fa4), loopSlotId);

                    loopSlotId = data_ov008_02090fa4->headerSlotIds[0];
                    position.x -= 0x38000;
                    Slot_SetPosition(PANEL_MAIN(data_ov008_02090fa4), loopSlotId, &position);
                    Obj_CommitAlphaBlend(PANEL_MAIN(data_ov008_02090fa4), loopSlotId);
                } else {
                    Obj_CommitAlphaBlend(PANEL_MAIN(context),
                                  context->rowSlotIds[loopIndex + 3]);
                }
                loopIndex = (loopIndex + 1) & 0xff;
            } while (loopIndex < 4);
        }

        context = data_ov008_02090fa4;
        if (context->activeRow == 0) {
            Obj_CommitAlphaBlend(PANEL_MAIN(context), context->rowSlotIds[0]);
            slotId = data_ov008_02090fa4->headerSlotIds[0];
            position.x = 0x38;
            position.y = 0x98;
            position.x <<= 12;
            position.y <<= 12;
            Slot_SetPosition(PANEL_MAIN(data_ov008_02090fa4), slotId, &position);
            Obj_CommitAlphaBlend(PANEL_MAIN(data_ov008_02090fa4), slotId);
        } else {
            Obj_CommitAlphaBlend(PANEL_MAIN_SPLIT(context),
                          context->rowSlotIds[1]);
        }
        break;

    case 2:
    case 3:
        if (context->selectedEntry >= 0) {
            slotId = context->headerSlotIds[1];
            Slot_ForwardToEntry(PANEL_MAIN(context), slotId,
                          (u16)context->selectedEntry);
            Obj_CommitAlphaBlend(PANEL_MAIN(data_ov008_02090fa4), slotId);
        }

        contextSlot = &data_ov008_02090fa4;
        index = 0;
        do {
            Obj_CommitAlphaBlend(PANEL_MAIN(*contextSlot),
                          (*contextSlot)->rowSlotIds[index + 3]);
            index = (index + 1) & 0xff;
        } while (index < 4);

        context = data_ov008_02090fa4;
        if (context->secondaryGroupVisible != 0) {
            Obj_CommitAlphaBlend(PANEL_MAIN(context), context->rowSlotIds[0]);
            context = data_ov008_02090fa4;
            Obj_CommitAlphaBlend(PANEL_MAIN_SPLIT(context),
                          context->rowSlotIds[1]);
            Obj_CommitAlphaBlend(PANEL_MAIN(data_ov008_02090fa4),
                          data_ov008_02090fa4->headerSlotIds[0]);
        }
        break;

    case 4:
    case 5:
    case 6:
        Obj_CommitAlphaBlend(PANEL_SUB(context), context->headerSlotIds[0]);
        Obj_CommitAlphaBlend(PANEL_SUB(data_ov008_02090fa4),
                      data_ov008_02090fa4->headerSlotIds[1]);

        {
            Ov006MissionModeUiView **loopContextSlot;
            u32 loopIndex;
            loopContextSlot = &data_ov008_02090fa4;
            loopIndex = 0;
            do {
                Obj_CommitAlphaBlend(PANEL_SUB(*loopContextSlot),
                              (*loopContextSlot)->rowSlotIds[loopIndex]);
                loopIndex = (loopIndex + 1) & 0xff;
            } while (loopIndex < 4);
        }

        {
            Ov006MissionModeUiView **loopContextSlot;
            u32 loopIndex;
            loopContextSlot = &data_ov008_02090fa4;
            loopIndex = 0;
            do {
                Obj_CommitAlphaBlend(PANEL_SUB(*loopContextSlot),
                              (*loopContextSlot)->secondarySlotIds[loopIndex]);
                loopIndex = (loopIndex + 1) & 0xff;
            } while (loopIndex < 3);
        }

        {
            Ov006MissionModeUiView **loopContextSlot;
            u32 loopIndex;
            loopContextSlot = &data_ov008_02090fa4;
            loopIndex = 0;
            do {
                Obj_CommitAlphaBlend(PANEL_SUB(*loopContextSlot),
                              (*loopContextSlot)->panelSlotIds[loopIndex]);
                loopIndex = (loopIndex + 1) & 0xff;
            } while (loopIndex < 7);
        }

        {
            u32 loopIndex;
            Ov006MissionModeUiView **loopContextSlot;
            loopContextSlot = &data_ov008_02090fa4;
            loopIndex = 0;
            context = *loopContextSlot;
            if (context->entryCount > 0) {
                do {
                    if (context->entryHandles[loopIndex] != 0) {
                        context = *loopContextSlot;
                        Obj_CommitAlphaBlend(PANEL_SUB(context),
                                      context->entryOverlaySlotIds[loopIndex]);
                    }
                    context = *loopContextSlot;
                    loopIndex = (loopIndex + 1) & 0xff;
                } while ((int)loopIndex < context->entryCount);
            }
        }

        Obj_CommitAlphaBlend(PANEL_MAIN(data_ov008_02090fa4),
                      data_ov008_02090fa4->overlayHeaderSlotIds[0]);
        Obj_CommitAlphaBlend(PANEL_MAIN(data_ov008_02090fa4),
                      data_ov008_02090fa4->overlayHeaderSlotIds[1]);

        context = data_ov008_02090fa4;
        if (context->selectedEntry >= 0) {
            Obj_CommitAlphaBlend(PANEL_MAIN(context), context->selectionMarkerSlotId);
        }

        contextSlot = &data_ov008_02090fa4;
        index = 0;
        context = data_ov008_02090fa4;
        if (context->entryCount > 0) {
            do {
                if (context->entryHandles[index] != 0) {
                    validity = Ov008_IsMissionSelectionEnabled(context->entryValues[index]);
                    if (validity != 0) {
                        context = *contextSlot;
                        if (context->entryFlags[index] != 0) {
                            Obj_CommitAlphaBlend(PANEL_MAIN(context),
                                          context->disabledEntrySlotIds[index]);
                        } else {
                            Obj_CommitAlphaBlend(PANEL_MAIN(context),
                                          context->emptyEntrySlotIds[index]);
                        }
                    } else {
                        context = *contextSlot;
                        Obj_CommitAlphaBlend(PANEL_MAIN(context),
                                      context->enabledEntrySlotIds[index]);
                    }
                }
                context = *contextSlot;
                index = (index + 1) & 0xff;
            } while ((int)index < context->entryCount);
        }

        contextSlot = &data_ov008_02090fa4;
        index = 0;
        do {
            validity = Ov008_IsMissionSelectionEnabled(index);
            if (validity != 0) {
                Obj_CommitAlphaBlend(PANEL_MAIN(*contextSlot),
                              (*contextSlot)->categoryMarkerSlotIds[index]);
            }
            index = (index + 1) & 0xff;
        } while (index < 0x13);
        break;

    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        break;
    }

    Obj_CommitAllSlots(PANEL_SUB(data_ov008_02090fa4));
    Obj_CommitAllSlots(PANEL_MAIN(data_ov008_02090fa4));
}