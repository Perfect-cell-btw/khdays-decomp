/* Unless the child is busy, kick anim (5, phase 1), clear +0x3c and dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov146_AiFaceWait(int);
void Ov146_AiEnterFace(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)owner, 5, 1);
    *(int *)(owner + 0x3c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov146_AiFaceWait);
}
