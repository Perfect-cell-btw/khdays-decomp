/* Copy the queued sub-state +0x1c7 into +0x1c6 (bail if -1) and dispatch the matching handler. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov192_ConfigHw60CopyVec3ConstThenAdvance(int);
extern int Ov192_SetupScaledVecThenAction4(int);
extern int Ov192_BeginShockwave(int);
void Ov192_AiDispatchAction(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int sub = *(signed char *)(*(int *)owner + 0x1c7);
    if (sub == -1) return;
    *(signed char *)(*(int *)owner + 0x1c6) = sub;
    switch (*(signed char *)(*(int *)owner + 0x1c6)) {
    case 0: SetIndexedSlot(param_1, 1, (void *)&Ov192_ConfigHw60CopyVec3ConstThenAdvance); break;
    case 1: SetIndexedSlot(param_1, 1, (void *)&Ov192_SetupScaledVecThenAction4); break;
    case 2: SetIndexedSlot(param_1, 1, (void *)&Ov192_BeginShockwave); break;
    }
    *(signed char *)(*(int *)owner + 0x1c7) = -1;
}
