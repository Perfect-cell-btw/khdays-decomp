/* Reset via 020cdfe8, store speed/3 into +0x7c; if armed (+0xac) and not already in sub-state 0xb,
 * set +0x88=8 and kick anims 0x32/0x36; always kick anim 1, restart 020c9ee8, clear +0x64, dispatch. */
extern int Ov252_CheckTarget(int, int, int);
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov107_StartAnim(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov252_HoverTick_2(int);
void Ov252_AiEnterIdleWithCharge(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov252_CheckTarget(param_1, 0, 1);
    *(int *)(owner + 0x7c) = *(int *)(*(int *)param_1 + 0x2c) / 3;
    if (*(int *)(owner + 0xac) != 0) {
        if (*(signed char *)(*(int *)owner + 0x1c8) != 0xb) {
            *(unsigned char *)(owner + 0x88) = 8;
            Ov107_PostTagUpdate(*(int *)owner, 0x32, 0);
            Ov107_PostTagUpdate(*(int *)owner, 0x36, 0);
        }
    }
    Ov107_PostTagUpdate(*(int *)owner, 1, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x574), 0, 0);
    *(int *)(owner + 0x64) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov252_HoverTick_2);
}
