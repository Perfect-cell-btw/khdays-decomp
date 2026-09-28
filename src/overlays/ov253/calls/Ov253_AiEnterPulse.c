/* Arm the 020c5af8 timer on the +0x388 sub-object, kick anim 1, clear +0x1c, then dispatch. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int Ov253_AiPulseTick(int);
void Ov253_AiEnterPulse(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_BuildAndSendUpdate(*(int *)(*(int *)owner + 0x388), 0x16b, 9, *(int *)owner + 0x74);
    Ov107_PostTagUpdate(*(int *)owner, 1, 0);
    *(int *)(owner + 0x1c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_AiPulseTick);
}
