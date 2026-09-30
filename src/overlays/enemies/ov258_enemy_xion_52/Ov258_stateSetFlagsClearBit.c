/* AI step: sets the stance bits 0x82, clears the model flag and continues with queuing action 1. */

struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov258_AiStep_QueueAction1IfActive(void);
void Ov258_stateSetFlagsClearBit(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x82) << 0x18) >> 0x10));
    }
    ((struct bf *)(*(int *)(*state + 0x3d4) + 8))->b &= ~1;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov258_AiStep_QueueAction1IfActive);
}
