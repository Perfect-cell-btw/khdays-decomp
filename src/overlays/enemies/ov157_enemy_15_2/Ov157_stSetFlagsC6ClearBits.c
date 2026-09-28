/* State step: sets state bits in the high byte of the actor's flags (+0x60), clears bit 0 of both
 * models' flag bytes and installs the queue-stored-action step. */

struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov157_AiStep_QueueStoredActionIfActive(void);

void Ov157_stSetFlagsC6ClearBits(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0xc6) << 0x18) >> 0x10));
    }
    ((struct bf *)(*(int *)(*state + 0x38c) + 8))->b &= ~1;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b &= ~1;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov157_AiStep_QueueStoredActionIfActive);
}
