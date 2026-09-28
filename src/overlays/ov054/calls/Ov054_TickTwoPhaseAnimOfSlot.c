extern void Ov054_TickTwoPhaseAnim(void *a, char *b);

void Ov054_TickTwoPhaseAnimOfSlot(void *a, char *b) {
    Ov054_TickTwoPhaseAnim(a, b + 0x10);
}
