extern void Ov107_RefreshAndSelectChild(int v, void *b);
extern void Ov107_ProcessObjectTick(void *a, void *b);

void Ov291_TickWithChildRefresh(char *a, void *b) {
    Ov107_RefreshAndSelectChild(*(int *)(a + 0x394), b);
    Ov107_ProcessObjectTick(a, b);
}
