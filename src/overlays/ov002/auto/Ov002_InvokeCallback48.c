/*
 * Invoke the optional callback stored at (*(param_1+8))+0x48, forwarding the three
 * incoming arguments. No-op when the slot is null.
 */
void Ov002_InvokeCallback48(int param_1, int param_2, int param_3) {
    void (*cb)(int, int, int) = *(void (**)(int, int, int))(*(int *)(param_1 + 8) + 0x48);

    if (cb != 0) {
        cb(param_1, param_2, param_3);
    }
}
