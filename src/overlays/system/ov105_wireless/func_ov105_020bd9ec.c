/* Constant-argument forwarding veneer onto Ov105_WMi_InitializeEx (fourth argument 0). */
extern void *Ov105_WMi_InitializeEx();

void *func_ov105_020bd9ec(int a, void *b, void *c) {
    return Ov105_WMi_InitializeEx(a, b, c, 0);
}
