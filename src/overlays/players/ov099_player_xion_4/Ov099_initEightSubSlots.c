/* Initialises the eight emitter objects (+0x234, 0x170 bytes each): registers each one's effect
 * sequence for the owner's palette slot and records its index in state 0. */

extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern int gOv099RoxasLiE0PackPath[];
void Ov099_initEightSubSlots(int this) {
    int obj = *(int *)(this + 0xdb4);
    int i = 0;
    int base = this + 0x234;
    do {
        RegisterSeqAndInit(base, gOv099RoxasLiE0PackPath, 1, ((unsigned char *)obj)[9] + 7);
        *(unsigned char *)(base + 0x12d) = i;
        *(unsigned char *)(base + 0x12c) = 0;
        base += 0x170;
        i++;
    } while (i < 8);
}
