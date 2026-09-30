/* Unless the child is busy, kick anim (1, phase 1), mark state 0 and dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, int);
void Ov146_Mount_AiRiseWait(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 8) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)owner, 1, 1);
    *(signed char *)(*(int *)owner + 0x1c7) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
