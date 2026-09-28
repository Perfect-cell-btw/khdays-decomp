/* Notify 020d0878, advance +0x20 by the frame delta, emit three 020d0f0c pulses, then unless
 * busy latch sub-state 2 and dispatch. */
extern int Ov238_TargetGap(int);
extern int Ov238_TimedCue(int, int, int, int);
extern int SetIndexedSlot(int, int, void *);
void Ov238_AiSwipeTick(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov238_TargetGap(param_1);
    *(int *)(owner + 0x20) += *(int *)(*(int *)param_1 + 0x2c);
    Ov238_TimedCue(param_1, 0x19, 2, 5);
    Ov238_TimedCue(param_1, 0xf, 3, 4);
    Ov238_TimedCue(param_1, 0x23, 1, 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    *(unsigned char *)(*(int *)owner + 0x1c7) = 2;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
