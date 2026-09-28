/* Clear +0x54/+0x4c, set +0x69, kick anim 0x19, then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov256_StompTick(int);
void Ov256_AiEnterStomp(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x54) = 0;
    *(int *)(owner + 0x4c) = 0;
    *(signed char *)(owner + 0x69) = 1;
    Ov107_PostTagUpdate(*(int *)owner, 0x19, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_StompTick);
}
