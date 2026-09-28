extern void Ov035_TickTwoPhaseAnim(void *a, char *b);

void Ov035_TickTwoPhaseAnimOfSlot(void *a, char *b) {
    Ov035_TickTwoPhaseAnim(a, b + 0x10);
}
