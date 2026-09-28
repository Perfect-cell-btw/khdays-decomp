/* Ov266_RearmEmitters -- re-arm the three emitter channels from the current stance, then stop.
 *
 * One of a 3-member shape family; the twins live in ov212/ov267 and are byte-identical modulo
 * relocs (matched here, fanned out with dedupprop).
 *
 * Three SetSubitemState calls against *(int *)(obj + 0x384), for channels 0, 4 and 2. All three pass
 * the same stance bit (bit 0 of the byte at +0x311) as the LAST argument; only channel 2 carries a
 * payload, the signed byte at +0x310. Then RefreshObjectCallbacks(..., 0) stops it.
 *
 * The stance bit is a bitfield, not an `& 1`: the ROM's `lsl #0x1f ; lsr #0x1f` is the unsigned
 * 1-bit extract, where `& 1` would emit `and rX, rY, #1` (codegen-cracks.md).
 *
 * The byte at +0x310 is read through a split base (`add r0, r4, #0x300 ; ldrsb r2, [r0, #0x10]`)
 * because ldrsb only has an 8-bit offset. mwcc does that split for you -- do not hand-write it. */

typedef struct {
    unsigned char b0 : 1;
    unsigned char rest : 7;
} Bits8;

extern void SetSubitemState(int a, int b, int c, int d);
extern void RefreshObjectCallbacks(int a, int b);

void Ov266_RearmEmitters(int obj) {
    SetSubitemState(*(int *)(obj + 0x384), 0, 0, ((Bits8 *)(obj + 0x311))->b0);
    SetSubitemState(*(int *)(obj + 0x384), 4, 0, ((Bits8 *)(obj + 0x311))->b0);
    SetSubitemState(*(int *)(obj + 0x384), 2, *(signed char *)(obj + 0x310),
                  ((Bits8 *)(obj + 0x311))->b0);
    RefreshObjectCallbacks(*(int *)(obj + 0x384), 0);
}
