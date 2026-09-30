/* Kick anim 0x13 and the +0x3d0 sub-anim 0x10, reset four fields, then dispatch. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov107_StartAnim(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov257_WhirlFinishTick(int);
void Ov257_AiEnterWhirlFinish(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 0x13, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x3d0), 0x10, 0);
    *(signed char *)(owner + 0x73) = 0;
    *(int *)(owner + 0x44) = 0;
    *(int *)(owner + 0x54) = 0;
    *(signed char *)(owner + 0x76) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov257_WhirlFinishTick);
}
