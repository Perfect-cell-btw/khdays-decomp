/* Gate a deferred action for slot param_1: when param_2 (a frame budget) is 0, allow
 * only if bit 0 of the global flags (gPadPressed) is set; otherwise allow only if the
 * available thread/frame count (OS_IsThreadAvailable) is at least param_2, else enqueue
 * the fallback (Slot48_StoreAtCurrentIndex) and deny. Returns 1 to proceed, 0 to skip. */
#pragma thumb on
extern unsigned int VBlank_GetCount(void);
extern void Slot48_StoreAtCurrentIndex(int a, unsigned int b);
extern unsigned short gPadPressed;
int DeferredAction_Gate(int param_1, unsigned int param_2) {
    if (param_2 == 0) {
        if (gPadPressed & 1) return 1;
        return 0;
    }
    if (VBlank_GetCount() < param_2) {
        Slot48_StoreAtCurrentIndex(param_1, param_2);
        return 0;
    }
    return 1;
}
