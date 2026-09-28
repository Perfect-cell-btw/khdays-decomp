/* Notify the peer of a hit: only while bit 0 of the flag byte at +0x694 is set, and only when the
 * slot at +8 still belongs to the local player, the object is not marked at bit 16, and the target
 * is within 0x2000 -- then flag 1 goes into the message word.
 *
 * Matched byte-exact 2026-07-23, closing an old park. Two things were wrong. The guard is a
 * BITFIELD read (`lsl #0x1f / lsrs #0x1f`), not `& 1`, which mwcc renders as `tst`. And the flag
 * has to be set with the compound form `flags |= 1`: written as `flags = flags | 1` mwcc constant
 * -folds it to `mov #1` and drops the 16-bit truncation the ROM keeps. */
struct Bit0 { unsigned char b0 : 1; };

extern int Session_GetLocalPlayerIndex(void);
extern int VEC_Distance(int *a, int *b);
extern void Slot_Spawn(unsigned int a, unsigned int b, int *c, unsigned int d);

void Ov022_NotifyPeerHit(unsigned int *param_1, int *param_2, unsigned int param_3,
                         unsigned int param_4) {
    unsigned short uVar3 = 0;
    if (((struct Bit0 *)((char *)param_1 + 0x694))->b0 == 0) {
        return;
    }
    if (*(unsigned char *)(param_1 + 2) == Session_GetLocalPlayerIndex() &&
        (*param_1 & 0x10000) == 0 &&
        VEC_Distance((int *)(param_1 + 0x123), param_2) <= 0x2000) {
        uVar3 |= 1;
    }
    Slot_Spawn(param_3, param_4, param_2, uVar3);
}
