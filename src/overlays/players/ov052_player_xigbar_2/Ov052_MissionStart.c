/* Mission start of the ov032 script (and its byte-identical twins): clears the +0x2e78 block
 * of the mission root (its +0x114 byte and first two words), binds its +0xc entry to the
 * overlay's descriptor with the root's +9 slot plus 7, registers the actor's +0x2648 item
 * (kind 5) with the overlay's parameter set and runs the first stage (4da4). */
extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern void Ov052_OpenSubObject(int a);
extern int data_ov052_020b80c0;
extern int gOv052XigbarLiE1PackPath;

typedef struct { int w[5]; } Params;
extern Params data_ov052_020b7f24;

void Ov052_MissionStart(int self)
{
    int base = *(int *)&data_ov052_020b80c0;
    Params p;
    char *blk;

    blk = (char *)(base + 0x2e78);
    *(signed char *)(blk + 0x114) = 0;
    *(int *)blk = 0;
    *(int *)(blk + 4) = 0;
    RegisterSeqAndInit((int)(blk + 0xc), &gOv052XigbarLiE1PackPath, 1, *(unsigned char *)(base + 9) + 7);
    p = data_ov052_020b7f24;
    Ov022_AllocateSlotWithClass(self + 0x2648, *(unsigned char *)(self + 9), 5, &p);
    Ov052_OpenSubObject(base);
}
