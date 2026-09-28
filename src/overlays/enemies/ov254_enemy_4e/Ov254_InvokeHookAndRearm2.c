/* Notify Ov107_MoveNodeAndRelayout; if owner flag bit1 (param_1+0x40) is set, invoke the owner's
 * hook (*(param_1+0xc))(param_1,0) when present. Re-arm via RefreshObjectCallbacks(owner->f384,0),
 * and if the owner is in state 1 (+0x50), poke Ov254_QueueAction1(*(param_1+0x214)). */
extern void Ov107_MoveNodeAndRelayout(int a, int b);
extern void RefreshObjectCallbacks(int a, int b);
extern void Ov254_QueueAction1(int *a);
void Ov254_InvokeHookAndRearm2(int param_1, int param_2, void *param_3, int param_4) {
    Ov107_MoveNodeAndRelayout(param_1, param_2);
    if ((*(int *)(param_1 + 0x40) << 0x1e) >> 0x1f) {
        void (*fn)(int, int) = *(void (**)(int, int))(param_1 + 0xc);
        if (fn != 0) {
            fn(param_1, 0);
        }
    }
    RefreshObjectCallbacks(*(int *)(param_1 + 0x384), 0);
    if (*(int *)(param_1 + 0x50) == 1) {
        Ov254_QueueAction1(*(int **)(param_1 + 0x214));
    }
}
