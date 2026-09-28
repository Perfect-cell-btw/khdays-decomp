/* Accumulate the owner rate (+0x2c) into the child timer (+0x28); once it reaches
 * 0x6ee, clear flag 7 in the high byte at (*child)+0x60, stop the anim, and dispatch. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov292_AiStep_QueueAction4OnAnimEnd(void);
struct hi_020d1d28 { unsigned short pad : 8; unsigned short flags : 8; };
void Ov292_WaitThenAdvanceState(int param_1) {
    int child = *(int *)(param_1 + 4);
    int c = *(int *)(child + 0x28) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 0x28) = c;
    if (c < 0x6ee) return;
    ((struct hi_020d1d28 *)(*(int *)child + 0x60))->flags &= ~0x82;
    Ov107_PostTagUpdate(*(int *)child, 0, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov292_AiStep_QueueAction4OnAnimEnd);
}
