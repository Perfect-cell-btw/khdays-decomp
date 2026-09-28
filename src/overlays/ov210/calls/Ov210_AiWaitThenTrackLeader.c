/* Accumulate the owner rate (+0x2c) into the timer at (child)+0x2c; once it reaches
 * 0x1800, dispatch to the handler. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov210_TrackLeaderRangeCheck(int);
void Ov210_AiWaitThenTrackLeader(int param_1) {
    int child = *(int *)(param_1 + 4);
    int t = *(int *)(child + 0x2c) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 0x2c) = t;
    if (t < 0x1800) return;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov210_TrackLeaderRangeCheck);
}
