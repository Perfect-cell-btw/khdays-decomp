/* Ov024_MobiClip_ResolveStreamDescs -- open the up-to-three streams a MobiClip descriptor asks for.
 * The descriptor is three 8-halfword records; a record whose first halfword is 2 is opened
 * with ByteCode_ResolveOperand and its handle kept. The three handles (0 for the records that were not
 * opened) are handed to Ov024_MobiClip_StartPlayback. Always reports success.
 *
 * The three handles are zeroed with a CHAINED assignment. As three separate statements mwcc
 * picks the FIRST handle for the stack slot and keeps the third in a register; the chain
 * initialises them in the opposite order and swaps that choice, which is what the ROM does
 * (`adds r7, r0, #0` for the first handle, `str` for the third). */
extern int ByteCode_ResolveOperand(int owner, short *entry);
extern void Ov024_MobiClip_StartPlayback(int a, int b, int c);

int Ov024_MobiClip_ResolveStreamDescs(int owner, short *desc) {
    int h0;
    int h1;
    int h2;

    h0 = h1 = h2 = 0;
    if (desc[0] == 2) {
        h0 = ByteCode_ResolveOperand(owner, desc);
    }
    if (desc[4] == 2) {
        h1 = ByteCode_ResolveOperand(owner, desc + 4);
    }
    if (desc[8] == 2) {
        h2 = ByteCode_ResolveOperand(owner, desc + 8);
    }
    Ov024_MobiClip_StartPlayback(h0, h1, h2);
    return 1;
}
