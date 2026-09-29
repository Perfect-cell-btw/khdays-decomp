/* Read three operands out of the script arguments -- at +0, +8 and +0x10 -- and
 * drive the widget with them. The first two are narrowed on the way in (byte and
 * halfword, hence the lsl/lsr pairs rather than an `and`); the third is passed
 * whole to Ov002_RefreshActiveSlots alongside whatever the first call returns.
 * Always reports 1. */

#include "game/engine.h"

extern int Ov002_List_ScaleEntryTag(int a, int b);
extern void Ov002_RefreshActiveSlots(int handle, int c);

int Ov002_ScriptDriveWidget(void *self, char *args) {
    int a = ScriptVm_ReadOperandInt(self, args);
    int b = ScriptVm_ReadOperandInt(self, args + 8);
    int c = ScriptVm_ReadOperandInt(self, args + 0x10);

    Ov002_RefreshActiveSlots(Ov002_List_ScaleEntryTag((unsigned char)a, (unsigned short)b), c);
    return 1;
}
