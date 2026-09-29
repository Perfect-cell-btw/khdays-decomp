/* Accumulate the owner rate (+0x2c) into the child timer (+0x4c); once it reaches
 * 0x666, stop the anim, run Ov248_startAnim, reset the timer, and dispatch. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov248_startAnim(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov248_AiMoveUntilAnimEnd(void);
void Ov248_TickTimerReleaseAtThreshold(int param_1) {
    int child = *(int *)(param_1 + 4);
    int c = *(int *)(child + 0x4c) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 0x4c) = c;
    if (c < 0x666) return;
    Ov107_PostTagUpdate(*(int *)child, 0, 0);
    Ov248_startAnim(*(int *)child, 0);
    *(int *)(child + 0x4c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov248_AiMoveUntilAnimEnd);
}
