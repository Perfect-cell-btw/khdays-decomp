/* Set the timer (+0x68=0x400) and clear +0x38 on the child, then dispatch to the handler. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov185_BoneSpin_Step(int);
void Ov185_AiEnterBoneSpin(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x68) = 0x400;
    *(int *)(child + 0x38) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov185_BoneSpin_Step);
}
