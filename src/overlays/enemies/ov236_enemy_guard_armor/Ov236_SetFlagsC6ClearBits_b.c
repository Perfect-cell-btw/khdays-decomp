/* AI step: sets the stance bits 0x86, clears both riders' model flags and continues with resuming
 * the stored action. */

struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov236_RidersB_AiStep_ResumeStoredAction(void);

void Ov236_SetFlagsC6ClearBits_b(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10));
    }
    ((struct bf *)(*(int *)(*state + 0x3c0) + 8))->b &= ~1;
    ((struct bf *)(*(int *)(*state + 0x3c4) + 8))->b &= ~1;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov236_RidersB_AiStep_ResumeStoredAction);
}
