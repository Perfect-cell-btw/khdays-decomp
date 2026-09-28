/* khdays: shared-bss */
/* Ov025_Hub_SelectMenuGroup -- highlight one of the hub's three menu groups (0: the seven main
 * entries, 1: entries 10/11, 2: entries 12/13), move the selector next to the chosen entry and
 * draw its caption. Twin of ov008 Ov008_SelectMenuGroupAndDrawCaption (byte-identical code; the ov025 build of
 * the same menu unit). The unused zero-initialised static fixes the order mwcc emits the two
 * local initialiser templates in ([12, 13] before [10, 11]). */

#include "nitro/types.h"

typedef struct {
    int x;
    int y;
} UiLayoutPos;

typedef enum {
    OV008_MENU_ID_NONE = 0
} Ov008MenuId;

typedef struct {
    Ov008MenuId ids[7];
} Ov008MenuIdList7;

typedef struct {
    Ov008MenuId ids[2];
} Ov008MenuIdList2;

typedef struct {
    Ov008MenuIdList2 group2;
    Ov008MenuIdList2 group1;
} Ov008MenuPairGroups;

typedef struct {
    int counts[3];
} Ov008MenuGroupCounts;

typedef struct {
    unsigned int words[4];
} Ov008LayoutTemplate;

typedef struct {
    Ov008MenuId ids[5];
} Ov008MenuIdList5;

typedef struct {
    u8 pad00[0x0c];
    int value0c;
} Ov008MenuEntry;

typedef struct {
    u8 pad00[4];
    u8 variables04[0x48];
    u8 surface4c[0x3c];
    int activeEntryValue88;
    void *entryHandle8c;
    void *entryHandle90;
    int alternateGroupActive94;
} Ov008MenuRenderer;

extern int Ov025_GetContext(void);
extern Ov008MenuEntry *Ov025_FindEntryById(int context, int id);
extern void Ov025_PushSubitemSet(
    int context, Ov008MenuEntry *entry, int value);
extern void Ov025_SetEntrySlotsVisible(
    int context, Ov008MenuEntry *entry, int visible);
extern int Ov025_UpdateMenuOptionLocksAndDrawCategory(Ov008MenuRenderer *renderer);
extern void Ov025_SwapParamOverrides(int context, Ov008MenuEntry *entry);
extern UiLayoutPos *Ov025_ApplyFirstValidSlot(int context, Ov008MenuEntry *entry);
extern void Ov025_ReleaseTwoSlotsEx(int context, Ov008MenuEntry *entry,
                                UiLayoutPos *position);
extern void *Ov025_GetVarRecordByIndex(void *variables, int index);
extern void Obj_InvokeInnerVtable4(void *surface);
extern void Text_DrawWithShadow(void *surface, int id, int x, int y,
                          void *buffer, int flags);
extern void EnqueueObjGfxCommand(void *surface);

extern const Ov008MenuIdList7 data_ov025_020b38b8;
extern const Ov008MenuGroupCounts data_ov025_020b3888;

void
Ov025_Hub_SelectMenuGroup(Ov008MenuRenderer *renderer, int selectedGroup)
{
    int itemIndex;
    int groupIndex;
    int context;
    unsigned int notSelected;
    Ov008MenuIdList7 group0 = data_ov025_020b38b8;
    Ov008MenuId group1[2] = {10, 11};
    Ov008MenuId group2[2] = {12, 13};
    /* Original overlay BSS context; shared_bss promotes this symbol at link time. */
    static int data_ov025_020b5744[2] = {0};
    Ov008MenuId *groups[3];
    Ov008MenuGroupCounts counts = data_ov025_020b3888;
    Ov008MenuEntry *entry;
    Ov008MenuEntry *selectorEntry;
    int captionIndex;
    int selectedEntryId;
    UiLayoutPos *selectorPosition;
    UiLayoutPos *selectedPosition;
    UiLayoutPos position;
    void *buffer;
    Ov008MenuId *currentGroup;
    int count;
    unsigned int selected;
    Ov008MenuEntry *loopEntry;

    context = Ov025_GetContext();
    groups[0] = group0.ids;
    groups[1] = group1;
    groups[2] = group2;

    for (groupIndex = 0; groupIndex < 3; ++groupIndex) {
        notSelected = selectedGroup != groupIndex;
        itemIndex = 0;
        if ((count = counts.counts[groupIndex]) > 0) {
            selected = notSelected == 0;
            currentGroup = groups[groupIndex];
            do {
                loopEntry = Ov025_FindEntryById(
                    context, currentGroup[itemIndex]);
                Ov025_PushSubitemSet(context, loopEntry, notSelected);
                loopEntry = Ov025_FindEntryById(
                    context, currentGroup[itemIndex]);
                Ov025_SetEntrySlotsVisible(context, loopEntry, selected);
                ++itemIndex;
            } while (itemIndex < count);
        }
    }

    switch (selectedGroup) {
    case 0:
        selectedEntryId = Ov025_UpdateMenuOptionLocksAndDrawCategory(renderer);
        captionIndex = -1;
        break;
    case 1:
        entry = Ov025_FindEntryById(context, 10);
        Ov025_PushSubitemSet(context, entry, renderer->entryHandle8c == 0);
        entry = Ov025_FindEntryById(context, 11);
        Ov025_PushSubitemSet(context, entry, renderer->entryHandle90 == 0);
        if (renderer->entryHandle8c != 0) {
            selectedEntryId = 10;
        } else {
            selectedEntryId = 11;
        }
        captionIndex = 0x12;
        break;
    case 2:
        selectedEntryId = 12;
        captionIndex = 13;
        break;
    }

    entry = Ov025_FindEntryById(context, selectedEntryId);
    Ov025_SwapParamOverrides(context, entry);
    renderer->activeEntryValue88 = entry->value0c;

    selectorEntry = Ov025_FindEntryById(context, 0x15);
    selectorPosition = Ov025_ApplyFirstValidSlot(context, selectorEntry);
    selectedPosition = Ov025_ApplyFirstValidSlot(context, entry);
    position.x = selectorPosition->x;
    position.y = selectedPosition->y;
    Ov025_ReleaseTwoSlotsEx(context, selectorEntry, &position);

    renderer->alternateGroupActive94 = selectedGroup != 0;
    if (captionIndex < 0) {
        return;
    }

    buffer = Ov025_GetVarRecordByIndex(renderer->variables04, captionIndex);
    Obj_InvokeInnerVtable4(renderer->surface4c);
    Text_DrawWithShadow(renderer->surface4c, 0x56, 0, 2, buffer, 1);
    EnqueueObjGfxCommand(renderer->surface4c);
}

