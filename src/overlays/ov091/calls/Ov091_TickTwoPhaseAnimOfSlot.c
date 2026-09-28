extern void Ov091_TickTwoPhaseAnim(void *a, char *b);

void Ov091_TickTwoPhaseAnimOfSlot(void *a, char *b) {
    Ov091_TickTwoPhaseAnim(a, b + 0x10);
}
