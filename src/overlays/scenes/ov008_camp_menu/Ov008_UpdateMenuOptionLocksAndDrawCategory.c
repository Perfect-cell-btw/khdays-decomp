/* Locks the camp-menu options the player has not unlocked yet (by story flags, level and linked
 * objects) and draws the category caption for the current progress. */

#include "nitro/types.h"

struct Ov008MenuRenderer {
    u8 field00[4];
    u8 variables[0x48];
    u8 surface[0x40];
    void *handle8c;
    void *handle90;
};

extern int Ov008_GetContext(void);
extern int GameState_GetField(int field, int index);
extern int GameState_IsFlagSet(int flag);
extern int Ov008_FindEntryById(int context, int id);
extern void Ov008_PushSubitemSet(int context, int entry, int value);
extern void *Ov008_GetVarRecordByIndex(void *variables, int index);
extern void Obj_InvokeInnerVtable4(void *surface);
extern void Text_DrawWithShadow(void *surface, int id, int x, int y,
                          void *buffer, int flags);
extern void EnqueueObjGfxCommand(void *surface);

int
Ov008_UpdateMenuOptionLocksAndDrawCategory(struct Ov008MenuRenderer *renderer)
{
    int result;
    int hasHandle;
    int hasLevel8;
    int hasAnyFlag;
    int i;
    int context;
    int level;
    int category;
    void *buffer;

    result = 0;
    hasHandle = result;
    hasLevel8 = result;
    hasAnyFlag = result;
    context = Ov008_GetContext();
    level = GameState_GetField(0, 9);

    for (i = 0; i < 0x39; i++) {
        if (GameState_IsFlagSet(i + 0x3c2b) != 0) {
            hasAnyFlag = 1;
            break;
        }
    }

    if (hasAnyFlag == 0) {
        Ov008_PushSubitemSet(context,
                            Ov008_FindEntryById(context, 4), 1);
    }

    if (level >= 8) {
        hasLevel8 = 1;
    } else {
        Ov008_PushSubitemSet(context,
                            Ov008_FindEntryById(context, 3), 1);
    }

    if (level >= 11) {
        result = 1;
    }
    if (result == 0) {
        Ov008_PushSubitemSet(context,
                            Ov008_FindEntryById(context, 1), 1);
    }

    if (renderer->handle8c != 0 || renderer->handle90 != 0) {
        hasHandle = 1;
    } else {
        Ov008_PushSubitemSet(context,
                            Ov008_FindEntryById(context, 2), 1);
    }

    if (result != 0) {
        category = 1;
        buffer = Ov008_GetVarRecordByIndex(renderer->variables, 9);
    } else if (hasHandle != 0) {
        category = 2;
        buffer = Ov008_GetVarRecordByIndex(renderer->variables, 10);
    } else if (hasLevel8 != 0) {
        category = 3;
        buffer = Ov008_GetVarRecordByIndex(renderer->variables, 12);
    } else if (hasAnyFlag != 0) {
        category = 4;
        buffer = Ov008_GetVarRecordByIndex(renderer->variables, 15);
    } else {
        category = 5;
        buffer = Ov008_GetVarRecordByIndex(renderer->variables, 11);
    }

    Obj_InvokeInnerVtable4(renderer->surface);
    Text_DrawWithShadow(renderer->surface, 0x56, 0, 2, buffer, 0);
    EnqueueObjGfxCommand(renderer->surface);
    return category;
}
