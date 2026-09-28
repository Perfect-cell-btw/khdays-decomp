/* Ov008_TweenSlotValue -- tween slot param_2's per-slot value (12 slots at obj+0x1278, stride 0x20)
 * from its current value (obj+slot*0x20+0x1294) to param_3 over param_4. Slot is clamped to 0..11. */
extern void Tween_Configure(unsigned int *interp, int mode, unsigned int from, unsigned int to, unsigned int dur);
extern void Tween_Start(unsigned int *interp);

void Ov008_TweenSlotValue(int param_1, int param_2, unsigned int param_3, unsigned int param_4) {
    unsigned int *interp;
    if (param_2 < 0) {
        param_2 = 0;
    }
    if (param_2 >= 0xc) {
        param_2 = 0xb;
    }
    interp = (unsigned int *)(param_1 + 0x1278 + param_2 * 0x20);
    Tween_Configure(interp, 2, *(unsigned int *)(param_1 + param_2 * 0x20 + 0x1294), param_3, param_4);
    Tween_Start(interp);
}
