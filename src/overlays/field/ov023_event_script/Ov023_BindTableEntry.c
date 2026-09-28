/* Ov023_BindTableEntry -- bind entry `Ov023_CountSubPanelEntries(a)` of the 0xc-byte table at +0x45c to
 * the handle Ov023_SubPanelColumnStep resolves from `b`, and mark it live (+8 = 1). */
extern int Ov023_CountSubPanelEntries(int a);
extern int Ov023_SubPanelColumnStep(int b);

void Ov023_BindTableEntry(int a, int b) {
    int *slot = (int *)((a + 0x45c) + Ov023_CountSubPanelEntries(a) * 0xc);
    slot[1] = Ov023_SubPanelColumnStep(b);
    slot[2] = 1;
}
