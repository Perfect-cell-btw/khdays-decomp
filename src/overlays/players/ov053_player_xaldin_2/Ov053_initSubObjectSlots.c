/* Initialises the character's effect block: clears its state, registers its effect sequence for the
 * owner's palette slot and binds tracks 0 and 2. */

extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern void BindAnimTrack(int a, int b, int c, int d);
extern int *data_ov053_020b7e60;
extern int data_ov053_020b7e34[];
void Ov053_initSubObjectSlots(void) {
    int obj = (int)data_ov053_020b7e60;
    int base = obj + 0x2ce4;
    *(int *)(base + 0x24) = 0;
    *(int *)base = 0;
    *(int *)(base + 0x10) = 0;
    *(int *)(base + 0xc) = 0;
    RegisterSeqAndInit(base + 0x28, data_ov053_020b7e34, 1, *(unsigned char *)(obj + 9) + 7);
    BindAnimTrack(base + 0x28, 0, base + 0x108, 0);
    BindAnimTrack(base + 0x28, 2, base + 0x108, 0);
}
