/* Kick anim 0x10, arm the 020c5af8 timer, set the +0x1ae bit, then dispatch. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov278_AiDownLoopStart(int);
void Ov278_AiEnterDown(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 0x10, 0);
    Ov107_BuildAndSendUpdate(*(int *)owner, 0x166, 0x10, *(int *)(owner + 0x38));
    *(unsigned short *)(*(int *)owner + 0x1ae) |= 1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov278_AiDownLoopStart);
}
