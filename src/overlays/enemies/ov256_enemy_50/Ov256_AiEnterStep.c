/* Kick the primary anim 0x1e and the +0x450 sub-anim 0xf, then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov107_StartAnim(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov256_StepTick(int);
void Ov256_AiEnterStep(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 0x1e, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x450), 0xf, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_StepTick);
}
