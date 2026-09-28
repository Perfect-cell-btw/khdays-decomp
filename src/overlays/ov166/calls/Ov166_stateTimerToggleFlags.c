struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
void Ov166_stateTimerToggleFlags(int *node) {
    int *state = (int *)node[1];
    int t = state[0x12] + *(int *)(*node + 0x2c);
    state[0x12] = t;
    if (t < 0xd48) return;
    ((struct hw60 *)(*state + 0x60))->hi &= ~1;
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x80) << 0x18) >> 0x10));
    }
    *(signed char *)(*state + 0x1c7) = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), 0);
}
