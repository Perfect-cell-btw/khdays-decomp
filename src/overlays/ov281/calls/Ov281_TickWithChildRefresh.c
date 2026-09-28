/* Refreshes the child selector at +0x3c0, then runs the object tick. */

extern void Ov107_RefreshAndSelectChild(int v, void *b);
extern void Ov107_ProcessObjectTick(void *a, void *b);

void Ov281_TickWithChildRefresh(char *a, void *b) {
    Ov107_RefreshAndSelectChild(*(int *)(a + 0x3c0), b);
    Ov107_ProcessObjectTick(a, b);
}
