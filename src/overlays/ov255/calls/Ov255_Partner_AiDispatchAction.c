/* Latch the queued sub-state into +0x1c6, reset +0x1c7, and dispatch the matching handler. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov255_ClearAndSetNodeFlags(int);
extern int Ov255_PartnerEnterTick(int);
void Ov255_Partner_AiDispatchAction(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int sub = *(signed char *)(*(int *)owner + 0x1c7);
    if (sub == -1) return;
    *(signed char *)(*(int *)owner + 0x1c6) = sub;
    *(signed char *)(*(int *)owner + 0x1c7) = -1;
    switch (*(signed char *)(*(int *)owner + 0x1c6)) {
    case 0: SetIndexedSlot(param_1, 1, (void *)&Ov255_ClearAndSetNodeFlags); break;
    case 1: SetIndexedSlot(param_1, 1, (void *)&Ov255_PartnerEnterTick); break;
    }
}
