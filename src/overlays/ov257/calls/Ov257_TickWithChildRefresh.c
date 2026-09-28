extern void Ov107_RefreshAndSelectChild(int v, void *b);
extern void Ov107_ProcessObjectTick(void *a, void *b);

void Ov257_TickWithChildRefresh(char *self, void *b) {
    if (*(unsigned short *)(self + 0x1ac) & 2) {
        b = 0;
    }
    Ov107_RefreshAndSelectChild(*(int *)(self + 0x3d0), b);
    Ov107_ProcessObjectTick(self, b);
}
