/* Latch the queued sub-state +0x1c7 into +0x1c6 (bail if -1), release the +0x2c partner via
 * 020ad8e0, dispatch the matching handler, then reset +0x1c7 to -1. */
extern int Ov022_ToggleBit13ByMode(int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov160_ConfigHw60CopyVec3ConstThenAdvance(int);
extern int Ov160_EnterDash(int);
void Ov160_SubAi_DispatchAction(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int sub = *(signed char *)(*(int *)owner + 0x1c7);
    if (sub == -1) return;
    *(signed char *)(*(int *)owner + 0x1c6) = sub;
    if (*(int *)(owner + 0x2c) != 0) {
        Ov022_ToggleBit13ByMode(*(int *)(owner + 0x2c), 0);
        *(int *)(owner + 0x2c) = 0;
    }
    switch (*(signed char *)(*(int *)owner + 0x1c6)) {
    case 0: SetIndexedSlot(param_1, 1, (void *)&Ov160_ConfigHw60CopyVec3ConstThenAdvance); break;
    case 1: SetIndexedSlot(param_1, 1, (void *)&Ov160_EnterDash); break;
    }
    *(signed char *)(*(int *)owner + 0x1c7) = -1;
}
