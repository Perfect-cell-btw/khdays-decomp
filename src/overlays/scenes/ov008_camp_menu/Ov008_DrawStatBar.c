/* Enqueue a bar-graph draw for column param_3: read its value (clamped to 0..100) and, if
 * positive, look up the column's colour record and hand everything to the bar renderer. */
extern int Load2DArrayU8_2(int a, int idx);
extern int Ov008_GetVarRecordByIndex(int obj, unsigned int idx);
extern void Ov008_AddListEntry(int p1, int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern unsigned int data_ov008_0208f778[];

void Ov008_DrawStatBar(int param_1, int param_2, int param_3, int param_4) {
    int count = Load2DArrayU8_2(0, param_3);
    int rec;
    if (count > 100) {
        count = 100;
    }
    if (count > 0) {
        rec = Ov008_GetVarRecordByIndex(param_1 + 0x58, data_ov008_0208f778[param_3]);
        Ov008_AddListEntry(param_1, param_3 + 0x74, 3, -1, count, 0, param_4, 1, rec, 0);
    }
}
