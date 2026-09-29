/* Enqueue a bar-graph draw for column param_3: read its value (clamped to 0..100) and, if
 * positive, look up the column's colour record and hand everything to the bar renderer. */

#include "game/engine.h"

extern int Ov025_GetVarRecordByIndex(int obj, unsigned int idx);
extern void Ov025_AddListEntry(int p1, int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern unsigned int data_ov025_020b44a0[];

void Ov025_DrawStatBar(int param_1, int param_2, int param_3, int param_4) {
    int count = Load2DArrayU8_2(0, param_3);
    int rec;
    if (count > 100) {
        count = 100;
    }
    if (count > 0) {
        rec = Ov025_GetVarRecordByIndex(param_1 + 0x58, data_ov025_020b44a0[param_3]);
        Ov025_AddListEntry(param_1, param_3 + 0x74, 3, -1, count, 0, param_4, 1, rec, 0);
    }
}
