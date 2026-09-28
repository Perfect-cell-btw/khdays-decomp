/* Clear bit 1 of the render flags at *(child+4)+0x5c, (re)configure the four spline
 * channels (indices 0,1,2,4 at rate 0), then register the handler. */
extern void SetSubitemState(int a, int b, int c, int d);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov206_WaitRigIdle(int);
void Ov206_ResetRigTracks(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(*(int *)(child + 4) + 0x5c) &= ~2;
    SetSubitemState(*(int *)(child + 4), 0, 0, 0);
    SetSubitemState(*(int *)(child + 4), 1, 0, 0);
    SetSubitemState(*(int *)(child + 4), 2, 0, 0);
    SetSubitemState(*(int *)(child + 4), 4, 0, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov206_WaitRigIdle);
}
