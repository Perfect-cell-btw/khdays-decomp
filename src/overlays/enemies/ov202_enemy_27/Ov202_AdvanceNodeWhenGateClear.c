/* Advance the node to state 9 once its gate byte reads zero.
 * The 0x44 gate is read UNSIGNED (ldrb) but the 0x20 selector stays SIGNED (ldrsb) --
 * the two byte reads have opposite signedness and swapping them costs the match. */
extern void SetIndexedSlot(void *a, int b, int c);
void Ov202_AdvanceNodeWhenGateClear(char *a) {
    char *p = *(char **)(a + 4);
    if (**(unsigned char **)(p + 0x44) != 0) return;
    (*(char **)p)[0x1c7] = 9;
    SetIndexedSlot(a, *(signed char *)(a + 0x20), 0);
}
