/* Unless the busy byte at *(child+4)+0xad is set, try to acquire the target (020d0ea4) into
 * (child)+0x10: if found, mark sub-state 4 and dispatch; otherwise play the anim (ov107 mode 1). */
extern int Ov268_PickBestFacingNode(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov107_PostTagUpdate(int a, int b, int c);
void Ov268_AiPickFacingNode(int param_1) {
    int child = *(int *)(param_1 + 4);
    int r;
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0) return;
    r = Ov268_PickBestFacingNode(*(int *)child, 0);
    *(int *)(child + 0x10) = r;
    if (r != 0) {
        *(signed char *)(*(int *)child + 0x1c7) = 4;
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
    } else {
        Ov107_PostTagUpdate(*(int *)child, 1, 0);
    }
}
