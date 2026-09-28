/* Ov008_BumpRowCounter -- bump the per-row counter at obj+0x1bf0[param_2] by param_3 and mirror it
 * into that row's widget (+5). If the list is not busy (obj+8 == 0), refresh the row
 * (Ov008_RefreshInventoryRow with the widget's owner at *node+0x14). */
extern int *Ov008_FindListObjectByKey(int obj, int a, int row);
extern void Ov008_RefreshInventoryRow(int obj, int owner);

void Ov008_BumpRowCounter(int param_1, int param_2, int param_3) {
    int counters = param_1 + 0x1bf0;
    int *node;
    *(unsigned char *)(counters + param_2) += param_3;
    node = Ov008_FindListObjectByKey(param_1, 0, param_2);
    if (node == 0) {
        return;
    }
    *(unsigned char *)((int)node + 5) = *(unsigned char *)(counters + param_2);
    if (*(int *)(param_1 + 8) != 0) {
        return;
    }
    Ov008_RefreshInventoryRow(param_1, *(int *)(*node + 0x14));
}
