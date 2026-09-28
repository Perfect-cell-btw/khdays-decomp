/* After Ov025_LayoutDetailPanel, set the object's position at +0x168 to
 * func_02020400(param_2 * (frame-0xc)*8, 0x60 - base) - 0x40 and mark +0x16c ready. */
extern int Ov025_LayoutDetailPanel(int obj, int nScroll);
extern int func_02020400(int a, int b);

void Ov025_DetailPanel_SetScroll(int param_1, int param_2) {
    int idx, v, r;
    Ov025_LayoutDetailPanel(param_1, param_2);
    idx = *(int *)(param_1 + 4);
    v = *(int *)(param_1 + idx * 4 + 0x144);
    r = func_02020400(param_2 * ((v - 0xc) << 3), 0x60 - *(int *)(param_1 + 0x164));
    *(int *)(param_1 + 0x168) = r - 0x40;
    *(int *)(param_1 + 0x16c) = 1;
}
