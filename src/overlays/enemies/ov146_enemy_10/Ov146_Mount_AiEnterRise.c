/* Kick anim 0, clear the child bit, arm the 020c5af8 timer, then dispatch. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov146_Mount_AiRiseWait(int);
void Ov146_Mount_AiEnterRise(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 0, 0);
    *(int *)(*(int *)(owner + 8) + 0x5c) &= ~2;
    Ov107_BuildAndSendUpdate(*(int *)owner, 0x125, 7, *(int *)(owner + 4) + 0xb0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov146_Mount_AiRiseWait);
}
