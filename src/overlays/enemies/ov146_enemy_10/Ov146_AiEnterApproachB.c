/* Kick the 7 animation on the object, then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov146_ApproachTick_2(int);
void Ov146_AiEnterApproachB(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 7, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov146_ApproachTick_2);
}
