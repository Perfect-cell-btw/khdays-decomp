/* Set +0x98, kick the idle animation, then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov252_ReturnTick(int);
void Ov252_AiEnterIdleArmed(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x98) = 1;
    Ov107_PostTagUpdate(*(int *)owner, 0, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov252_ReturnTick);
}
