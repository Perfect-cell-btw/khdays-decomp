/* Release any queued sub-request in the 5 slots at (param_1)+0x3e0 (second word non-zero),
 * clearing each as it is handled, then run the ov107 detach for the pair. */
extern void TaskList_FinishByTag(int a, int b);
extern void Ov107_Actor_DetachFromRegion(int a, int b);
struct row8_020cc804 { int p; int q; };
void Ov206_FinishPartTasksThenBase(int param_1, int param_2) {
    int i;
    for (i = 0; i < 5; i++) {
        int q = ((struct row8_020cc804 *)*(int *)(param_1 + 0x3e0))[i].q;
        if (q != 0) {
            TaskList_FinishByTag(*(int *)(param_1 + 0x3c), q);
            ((struct row8_020cc804 *)*(int *)(param_1 + 0x3e0))[i].q = 0;
        }
    }
    Ov107_Actor_DetachFromRegion(param_1, param_2);
}
