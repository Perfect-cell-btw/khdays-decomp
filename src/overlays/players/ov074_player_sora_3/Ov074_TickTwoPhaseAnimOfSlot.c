/* Ticks the two-phase animation of the slot's +0x10 block. */

extern void Ov074_TickTwoPhaseAnim(void *a, char *b, int dt);

void Ov074_TickTwoPhaseAnimOfSlot(void *a, char *b, int dt) {
    Ov074_TickTwoPhaseAnim(a, b + 0x10, dt);
}
