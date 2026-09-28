/* Kick the primary anim 1 and the +0x3a8 sub-anim 0, then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov107_StartAnim(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov235_TakeOffTick(int);
void Ov235_AiEnterTakeOff(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 1, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x3a8), 0, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov235_TakeOffTick);
}
