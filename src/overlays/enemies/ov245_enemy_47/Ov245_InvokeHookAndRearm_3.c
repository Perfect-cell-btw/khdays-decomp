/* Notify Ov107_MoveNodeAndRelayout; if owner flag bit1 (param_1+0x40) is set, invoke the owner's
 * hook (*(param_1+0xc))(param_1,0) when present. Re-arm via RefreshObjectCallbacks(owner->f384,0),
 * and if the owner is in state 1 (+0x50), forward param_3 to Ov245_StopAndLatch. */
extern void Ov107_MoveNodeAndRelayout(int a, int b);
extern void RefreshObjectCallbacks(int a, int b);
extern void Ov245_StopAndLatch(int *a, void *b);
void Ov245_InvokeHookAndRearm_3(int param_1, int param_2, void *param_3, int param_4) {
    Ov107_MoveNodeAndRelayout(param_1, param_2);
    if ((*(int *)(param_1 + 0x40) << 0x1e) >> 0x1f) {
        void (*fn)(int, int) = *(void (**)(int, int))(param_1 + 0xc);
        if (fn != 0) {
            fn(param_1, 0);
        }
    }
    RefreshObjectCallbacks(*(int *)(param_1 + 0x384), 0);
    if (*(int *)(param_1 + 0x50) == 1) {
        Ov245_StopAndLatch(*(int **)(param_1 + 0x214), param_3);
    }
}
