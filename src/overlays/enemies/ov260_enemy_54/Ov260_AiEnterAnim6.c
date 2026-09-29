/* Kick anim 6, clear +0x70/+0x7b, then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov260_ThrowTick(int);
void Ov260_AiEnterAnim6(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 6, 0);
    *(int *)(owner + 0x70) = 0;
    *(signed char *)(owner + 0x7b) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov260_ThrowTick);
}
