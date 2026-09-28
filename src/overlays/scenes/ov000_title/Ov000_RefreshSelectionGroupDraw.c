/* Walks the menu selection groups (stride from context+0x4b10). For each group it fetches the list
 * object and sets its draw mode from the group state: state 1 uses mode+2, state 2 uses 0,
 * otherwise 1; group index >= 3 forces mode 5. Each object also gets a base mode 3 first. */

#include "nitro/types.h"

typedef struct Ov000ObjectList {
    u8 data[0x4a80];
} Ov000ObjectList;

typedef struct Ov000SelectionGroup {
    u8 pad_00[0x10];
    int state;
    u8 pad_14[8];
    int mode;
} Ov000SelectionGroup;

typedef struct Ov000SceneContext {
    u8 pad_0000[0x4c];
    Ov000ObjectList objectList;
    u8 positionShifted;
    u8 pad_4acd[0x43];
    Ov000SelectionGroup selectionGroups[4];
} Ov000SceneContext;

typedef struct Ov000EntryIdGrid {
    int ids[4][8];
} Ov000EntryIdGrid;

extern Ov000SceneContext *volatile data_ov000_0205ac24;
extern Ov000EntryIdGrid data_ov000_0205a7ac;

extern int *Ov000_FindEntryById(Ov000ObjectList *objectList, int id);
extern void Ov000_SetEntrySlotsVisible(Ov000ObjectList *objectList, int *entry,
                                int visible);
extern void Ov000_ReleaseTwoSlotsEx(Ov000ObjectList *objectList, int *entry,
                                u16 mode);
extern void Ov000_ReleaseTwoSlotsEx_2(Ov000ObjectList *objectList, int *entry,
                                int mode);

void Ov000_RefreshSelectionGroupDraw(void) {
    Ov000SceneContext *context = data_ov000_0205ac24;
    int group = 0;
    int groupOffset = 0;
    unsigned int slot;

    do {
        Ov000SelectionGroup *selectionGroup =
            (Ov000SelectionGroup *)((u8 *)data_ov000_0205ac24 +
                                    0x4b10 + groupOffset);
        int *entry =
            Ov000_FindEntryById(&context->objectList, group + 1);

        Ov000_ReleaseTwoSlotsEx_2(&context->objectList, entry, 3);
        if (group >= 3) {
            Ov000_ReleaseTwoSlotsEx(&context->objectList, entry, 5);
        } else if (selectionGroup->state == 1) {
            Ov000_ReleaseTwoSlotsEx(
                &context->objectList, entry,
                (u16)(data_ov000_0205ac24->selectionGroups[group].mode + 2));
        } else if (selectionGroup->state == 2) {
            Ov000_ReleaseTwoSlotsEx(&context->objectList, entry, 0);
        } else {
            Ov000_ReleaseTwoSlotsEx(&context->objectList, entry, 1);
        }

        {
            for (slot = 0; slot < 8; slot++) {
                int id = data_ov000_0205a7ac.ids[group][slot];

                if (id != 0) {
                    entry = Ov000_FindEntryById(&context->objectList, id);
                    switch (slot) {
                    case 0:
                        if (data_ov000_0205ac24->positionShifted == 0 &&
                            group >= 3) {
                            Ov000_SetEntrySlotsVisible(&context->objectList, entry, 0);
                        } else {
                            Ov000_SetEntrySlotsVisible(&context->objectList, entry, 1);
                        }
                        break;
                    case 1:
                        Ov000_SetEntrySlotsVisible(&context->objectList, entry, 1);
                        break;
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                        if (group < 3) {
                            if (selectionGroup->state == 1) {
                                Ov000_SetEntrySlotsVisible(
                                    &context->objectList, entry, 1);
                            } else {
                                Ov000_SetEntrySlotsVisible(
                                    &context->objectList, entry, 0);
                            }
                        }
                        break;
                    }
                }
            }
        }

        group++;
        groupOffset += 0x20;
    } while (group < 4);
}
