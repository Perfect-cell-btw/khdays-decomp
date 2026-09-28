/* Pushes the stance byte at +0x310 out to state channels 0 and 2 of the sub-object at
 * +0x384, then closes the update.  The flag at +0x311 is a bitfield read (lsl#31/lsr#31),
 * not `& 1`. */
typedef struct {
    unsigned char b0 : 1;
    unsigned char rest : 7;
} Flags;

extern void SetSubitemState(void *sub, int channel, short value, int flag);
extern void RefreshObjectCallbacks(void *sub, int a);

void Ov245_Thrown_ApplyAnims(char *self) {
    SetSubitemState(*(void **)(self + 0x384), 0, *(signed char *)(self + 0x310),
                  ((Flags *)(self + 0x311))->b0);
    SetSubitemState(*(void **)(self + 0x384), 2, *(signed char *)(self + 0x310),
                  ((Flags *)(self + 0x311))->b0);
    RefreshObjectCallbacks(*(void **)(self + 0x384), 0);
}
