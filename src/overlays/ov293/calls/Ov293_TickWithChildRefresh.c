/* Refreshes the child selection, then runs the object tick. */

extern void Ov107_RefreshAndSelectChild(int v, void *b);
extern void Ov107_ProcessObjectTick(void *a, void *b);

void Ov293_TickWithChildRefresh(char *a, void *b) {
    Ov107_RefreshAndSelectChild(*(int *)(a + 0x39c), b);
    Ov107_ProcessObjectTick(a, b);
}
