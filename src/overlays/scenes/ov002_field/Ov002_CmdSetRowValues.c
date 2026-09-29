/* Script command: read four operands and set the values on a peer row.
 *
 * Operands are eight bytes apart, as everywhere in this command family. The first two go through
 * untouched; the third and fourth are narrowed to SIGNED bytes, which is what the row setter
 * expects, since it treats a negative fourth operand as "leave this field alone". The 0xffff
 * handed over as the third argument is the same idea for the middle field: the setter compares
 * against it and skips the write.
 *
 * Ghidra carries the operands as OperandSlot.
 */

#include "game/engine.h"

extern void Ov002_StampEntry(int a, int b, int c, int d, int e);

int Ov002_CmdSetRowValues(void *vm, char *table) {
    int first = ScriptVm_ReadOperandInt(vm, table);
    int second = ScriptVm_ReadOperandInt(vm, table + 8);
    int third = ScriptVm_ReadOperandInt(vm, table + 0x10);
    int fourth = ScriptVm_ReadOperandInt(vm, table + 0x18);

    Ov002_StampEntry(first, second, 0xffff, (signed char)fourth, (signed char)third);
    return 1;
}
