/* True when any of the 5 slots at +0x10c is positive and its bit is set in the
 * mask queried from BuildSlotMask.  Requires flag 4 of the halfword at +0x12.
 *
 * Two codegen notes:
 *  - The literal 4 does double duty: it is the flag tested at +0x12 and, shifted
 *    left by 10, the argument passed to BuildSlotMask.  Writing it as a local keeps
 *    the ROM's single `movs r1,#4` followed by `lsls r1,r1,#0xa`.
 *  - The guard's failure path must `goto` the shared `return 0` at the bottom;
 *    written as an inline `return 0` mwcc duplicates the epilogue instead of
 *    branching to it.
 */
extern int BuildSlotMask(int p, int mask);

int Ov002_IsAnySlotEnabled(int obj) {
    int four = 4;
    int mask;
    int i;
    int one;
    if ((*(unsigned short *)(obj + 0x12) & four) == 0) {
        goto zero;
    }
    mask = BuildSlotMask(obj + 0x2c, four << 0xa);
    i = 0;
    one = 1;
    do {
        if (*(short *)(obj + (unsigned short)i * 2 + 0x10c) > 0 &&
            ((one << i) & mask) != 0) {
            return one;
        }
        i = i + 1;
    } while (i < 5);
zero:
    return 0;
}
