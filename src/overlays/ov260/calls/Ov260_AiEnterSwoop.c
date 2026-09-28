/* Notify 020cd794, latch +0x68->+0x64, kick anim 0x12, restart sub-anim 020c9ee8, arm 020cd148
 * with +0x10, clear +0x79 and set +0x78=-1, then dispatch 020ce2f0. */
extern int Ov260_PickTarget(int);
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov107_StartAnim(int, int, int);
extern int Ov260_PlaySound(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov260_GlideTick(int);
void Ov260_AiEnterSwoop(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov260_PickTarget(param_1);
    *(int *)(owner + 0x64) = *(int *)(owner + 0x68);
    Ov107_PostTagUpdate(*(int *)owner, 0x12, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x428), 8, 0);
    Ov260_PlaySound(*(int *)owner, 0x18, *(int *)(owner + 0x10));
    *(unsigned char *)(owner + 0x79) = 0;
    *(signed char *)(owner + 0x78) = -1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov260_GlideTick);
}
