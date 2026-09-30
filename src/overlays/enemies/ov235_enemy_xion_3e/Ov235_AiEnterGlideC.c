/* Kick the 0x13/0 animation, set +0x54, then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov235_GlideTick14(int);
void Ov235_AiEnterGlideC(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 0x13, 0);
    *(int *)(owner + 0x54) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov235_GlideTick14);
}
