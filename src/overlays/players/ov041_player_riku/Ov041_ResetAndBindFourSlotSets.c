/* Initialises the character's effect block: clears the states and registers the six effect
 * sequences for the owner's palette slot. */

extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern int gOv041RikuLiE0PackPath;
extern int gOv041RikuLiE2PackPath;
extern int gOv041RikuLiE3PackPath;
extern int gOv041RikuLiE1PackPath;

void Ov041_ResetAndBindFourSlotSets(int self) {
    char *blk = (char *)(self + 0x84 + 0x2c00);
    int i;
    char *q;
    char *p;
    int j;
    *(int *)(self + 0x2000 + 0xc84) = 0;
    *(int *)(blk + 0x110) = 0;
    *(int *)(blk + 0x220) = 0;
    for (i = 0, p = blk; i < 3; i++, p += 0x110) {
        *(int *)(p + 0x330) = 0;
    }
    RegisterSeqAndInit((int)(blk + 4), &gOv041RikuLiE0PackPath, 1, *(unsigned char *)(self + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0x114), &gOv041RikuLiE2PackPath, 1, *(unsigned char *)(self + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0x224), &gOv041RikuLiE3PackPath, 1, *(unsigned char *)(self + 9) + 7);
    for (j = 0, q = blk + 0x334; j < 3; j++, q += 0x110) {
        RegisterSeqAndInit((int)q, &gOv041RikuLiE1PackPath, 1, *(unsigned char *)(self + 9) + 7);
    }
}
