extern void SetIndexedSlot();
extern void Ov295_LatchStateAndRender(void);
void Ov295_stSetDispFlagsde(int node) {
    int *s = *(int **)(node + 4);
    unsigned int h = *(unsigned short *)(*s + 0x60);
    *(unsigned short *)(*s + 0x60) = (h & ~0xff00) | (((((h << 0x10) >> 0x18) | 0xde) << 0x18) >> 0x10);
    SetIndexedSlot(node, *(signed char *)(node + 0x20), Ov295_LatchStateAndRender);
}
