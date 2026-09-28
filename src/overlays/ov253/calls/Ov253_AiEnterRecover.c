/* Unless the child gate byte is set, kick anim 4 and dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov253_AiRecoverRollTimer(int);
void Ov253_AiEnterRecover(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4)) != 0) return;
    Ov107_PostTagUpdate(*(int *)owner, 4, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_AiRecoverRollTimer);
}
