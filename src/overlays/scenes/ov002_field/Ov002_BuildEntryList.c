/*
 * Count the table's entries, map each one, and hand the resulting list on.
 *
 * The table is walked eight bytes at a time starting one entry in, and each entry is turned
 * into an item by 02021948; the ten items live on the stack and go to ov002_0206cd84 with the
 * count. The return is always 1.
 *
 * The walking cursor is the PARAMETER itself, not a local, and that is what the ROM requires:
 * a local pointer gets r4 and pushes the array cursor to r5, while the parameter reuses its own
 * storage, takes r5 and leaves r4 for the array. The advance is written before the count call
 * so the plus eight lands ahead of the branch-and-link with the parameter spill interleaved
 * between the two adds, which is why the original is passed to that call through a saved copy.
 */

#include "game/engine.h"

extern void Ov002_SetNameTable(int count, void **items);

int Ov002_BuildEntryList(void *a, char *table) {
    void *items[10];
    int count;
    int i;
    char *first = table;

    table += 8;
    count = ScriptVm_ReadOperandInt(a, first);
    for (i = 0; i < count; i++) {
        void *x = ByteCode_ResolveOperand(a, table);
        table += 8;
        items[i] = x;
    }
    Ov002_SetNameTable(count, items);
    return 1;
}
