extern void Ov074_TickTwoPhaseAnim(void *a, char *b);

void Ov074_TickTwoPhaseAnimOfSlot(void *a, char *b) {
    Ov074_TickTwoPhaseAnim(a, b + 0x10);
}
