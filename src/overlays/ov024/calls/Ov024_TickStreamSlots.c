/* MobiClip player: tick both stream slots and latch "all done". Runs Ov024_MobiClip_TickSlot on the
 * slot at +8 and the one at +0xc of the stream block; when BOTH report ready, the completion
 * flag at +0xe4 of the player block is set.
 *
 * It RETURNS the AND, and that is what makes it match: the original emits `ands r0,r4,r0` and
 * leaves the result in r0 all the way to the pop, which a void function has no reason to do --
 * mwcc writes `tst r4,r0` and the three following words differ only in the register numbering
 * carried from that choice. Same signal as Ov008_ArmCueRequest: if the original never clobbers
 * r0 after computing something, the something is the return value. */
extern unsigned int Ov024_MobiClip_TickSlot(int *slot);
extern int data_ov024_02093a2c[];
extern int data_ov024_0209ba48[];

unsigned int Ov024_TickStreamSlots(void) {
    unsigned int lo;
    unsigned int hi;

    lo = Ov024_MobiClip_TickSlot((int *)data_ov024_02093a2c[2]);
    hi = Ov024_MobiClip_TickSlot((int *)data_ov024_02093a2c[3]);
    lo = lo & hi;
    if (lo != 0) {
        data_ov024_0209ba48[0x39] = 1;
    }
    return lo;
}
