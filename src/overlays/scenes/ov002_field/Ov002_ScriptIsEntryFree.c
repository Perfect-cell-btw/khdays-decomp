/* Script opcode: resolve the entry named by operands 0 and 8, and report whether
 * it is still usable. Only kind-6 entries are actually consulted -- for anything
 * else the answer is a plain yes. Reports 1 when Ov002_IsAnySlotEnabled says the
 * entry is free, 0 when it hands something back.
 *
 * The two operands are narrowed on the way in (byte and halfword, hence the
 * lsl/lsr pairs rather than an `and`), the same shape as
 * Ov002_ScriptDriveWidget. */

#include "game/engine.h"

extern void *Ov002_List_ScaleEntryTag(int a, int b);
extern int Ov002_IsAnySlotEnabled(void *entry);

int Ov002_ScriptIsEntryFree(void *self, char *args) {
    int busy = 0;
    int a = ScriptVm_ReadOperandInt(self, args);
    int b = ScriptVm_ReadOperandInt(self, args + 8);
    void *entry = Ov002_List_ScaleEntryTag((unsigned char)a, (unsigned short)b);

    if (*(unsigned short *)(*(int *)((char *)entry + 8) + 0x4c) == 6) {
        busy = Ov002_IsAnySlotEnabled(entry);
    }

    if (busy != 0) {
        return 0;
    }
    return 1;
}
