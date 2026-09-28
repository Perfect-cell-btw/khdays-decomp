/* Ticks the two-phase animation of the slot's +0x10 block. */

extern void Ov035_TickTwoPhaseAnim(void *a, char *b, int dt);

void Ov035_TickTwoPhaseAnimOfSlot(void *a, char *b, int dt) {
    Ov035_TickTwoPhaseAnim(a, b + 0x10, dt);
}
