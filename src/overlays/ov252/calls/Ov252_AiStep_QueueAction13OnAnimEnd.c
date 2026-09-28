/* Run 020ce370; unless the child is busy, clear +0xa0, mark state 0xd and dispatch. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov252_GuardSweep(int);
void Ov252_AiStep_QueueAction13OnAnimEnd(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov252_GuardSweep(param_1);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    *(int *)(owner + 0xa0) = 0;
    *(signed char *)(*(int *)owner + 0x1c7) = 0xd;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
