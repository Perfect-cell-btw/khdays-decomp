struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov194_AiStep_QueueStoredActionIfActive(void);

void Ov194_stSetFlags86Clear(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10));
    }
    ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b &= ~1;
    state[0x11] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov194_AiStep_QueueStoredActionIfActive);
}
