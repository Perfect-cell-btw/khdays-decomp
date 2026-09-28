/* Latch the queued sub-state +0x1c7 into +0x1c6 (bail if -1), clear bit4 of +0x1ae, dispatch the
 * matching handler, then reset +0x1c7 to -1. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov245_EnterState1854(int);
extern int Ov245_StartWindup(int);
extern int Ov245_BurstEntry(int);
void Ov245_Thrown_AiDispatchAction(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int sub = *(signed char *)(*(int *)owner + 0x1c7);
    if (sub == -1) return;
    *(signed char *)(*(int *)owner + 0x1c6) = sub;
    *(unsigned short *)(*(int *)owner + 0x1ae) &= ~0x10;
    switch (*(signed char *)(*(int *)owner + 0x1c6)) {
    case 0: SetIndexedSlot(param_1, 1, (void *)&Ov245_EnterState1854); break;
    case 1: SetIndexedSlot(param_1, 1, (void *)&Ov245_StartWindup); break;
    case 2: SetIndexedSlot(param_1, 1, (void *)&Ov245_BurstEntry); break;
    }
    *(signed char *)(*(int *)owner + 0x1c7) = -1;
}
