/* Dispatch to SetIndexedSlot with param_1, its signed byte at +0x20, and handler Ov146_Rider_IdleStep. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov146_Rider_IdleStep(void);
int Ov146_stAdvanceState_ccedc_2(int param_1) {
    return SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov146_Rider_IdleStep);
}
