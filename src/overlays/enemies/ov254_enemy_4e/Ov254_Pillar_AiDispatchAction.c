/* Clear the linked node's +0x4e0, latch the queued sub-state +0x1c7 into +0x1c6, dispatch the
 * matching handler, then reset +0x1c7 to -1. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov254_UnlinkEntry(int);
extern int Ov254_HoldEntry(int);
extern int Ov254_ArmEntry(int);
void Ov254_Pillar_AiDispatchAction(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(*(int *)(*(int *)owner + 0x390) + 0x4e0) = 0;
    int sub = *(signed char *)(*(int *)owner + 0x1c7);
    if (sub != -1) {
        *(signed char *)(*(int *)owner + 0x1c6) = sub;
        switch (*(signed char *)(*(int *)owner + 0x1c6)) {
        case 0: SetIndexedSlot(param_1, 1, (void *)&Ov254_UnlinkEntry); break;
        case 1: SetIndexedSlot(param_1, 1, (void *)&Ov254_HoldEntry); break;
        case 2: SetIndexedSlot(param_1, 1, (void *)&Ov254_ArmEntry); break;
        }
    }
    *(signed char *)(*(int *)owner + 0x1c7) = -1;
}
