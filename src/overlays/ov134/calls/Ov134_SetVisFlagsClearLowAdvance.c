extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov134_AiStep_QueueStoredActionIfActive(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct LowByteFlags { unsigned bits : 8; };

void Ov134_SetVisFlagsClearLowAdvance(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short hw60 = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10);
    }
    ((struct LowByteFlags *)(*(int *)(*state + 0x38c) + 8))->bits &= ~1;
    *(unsigned char *)((char *)state + 0x42) &= ~1;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov134_AiStep_QueueStoredActionIfActive);
}
