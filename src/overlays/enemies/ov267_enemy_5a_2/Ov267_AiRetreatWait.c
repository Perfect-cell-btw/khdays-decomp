/* If ov212_020cd63c(child, 1) reports ready, register the handler and return. Otherwise, unless
 * ov212_020cd63c(child, 0) is still busy, mark sub-state 2 and dispatch with no handler. */
extern int Ov267_IsState6cActive(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov267_PickRetreatSpot(int);
void Ov267_AiRetreatWait(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (Ov267_IsState6cActive(child, 1) != 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov267_PickRetreatSpot);
        return;
    }
    if (Ov267_IsState6cActive(child, 0) != 0) return;
    *(signed char *)(*(int *)child + 0x1c7) = 2;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
