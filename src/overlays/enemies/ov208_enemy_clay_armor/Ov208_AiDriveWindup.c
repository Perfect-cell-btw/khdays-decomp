/* Accumulate the owner rate (+0x2c) into the timer at (child)+0x2c; once it reaches 0x110,
 * play the anim (ov107 mode 8), reset the timer and dispatch. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov208_MidWindowDriveAnchors(int);
void Ov208_AiDriveWindup(int param_1) {
    int child = *(int *)(param_1 + 4);
    int t = *(int *)(child + 0x2c) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 0x2c) = t;
    if (t < 0x110) return;
    Ov107_PostTagUpdate(*(int *)child, 8, 0);
    *(int *)(child + 0x2c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov208_MidWindowDriveAnchors);
}
