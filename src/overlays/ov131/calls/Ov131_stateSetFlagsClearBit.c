extern void SetIndexedSlot(int, int, void *);
extern void Ov131_AiStep_QueueStoredActionIfActive(void);

struct flagword { unsigned f8 : 8; };

void Ov131_stateSetFlagsClearBit(int param_1) {
    void *cb = Ov131_AiStep_QueueStoredActionIfActive;
    int *node = *(int **)(param_1 + 4);
    int obj = *node;
    unsigned short h = *(unsigned short *)(obj + 0x60);

    *(unsigned short *)(obj + 0x60) =
        h & ~0xff00 | (((((unsigned int)h << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10);
    ((struct flagword *)(*(int *)(*node + 0x388) + 8))->f8 &= ~1;
    SetIndexedSlot(param_1, *(char *)(param_1 + 0x20), cb);
}
