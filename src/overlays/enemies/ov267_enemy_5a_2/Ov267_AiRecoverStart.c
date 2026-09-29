/* Unless the busy byte at *(child+4)+0xad is set, play the anim (ov107 mode 5,1), run the
 * local setup (mode 0) and register the handler. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov267_ResetTracking(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov267_SteerTowardAnchorTick(int);
void Ov267_AiRecoverStart(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)child, 5, 1);
    Ov267_ResetTracking(*(int *)child, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov267_SteerTowardAnchorTick);
}
