/* Ticks the two-phase animation of the slot's +0x10 block. */

extern void Ov054_TickTwoPhaseAnim(void *a, char *b, int dt);

void Ov054_TickTwoPhaseAnimOfSlot(void *a, char *b, int dt) {
    Ov054_TickTwoPhaseAnim(a, b + 0x10, dt);
}
