/* Initialises the secondary effect record, registers its sequence for the owner's palette slot and
 * opens the secondary sub-objects. */

extern void RegisterSeqAndInit(int a, int b, int c, int d);
extern void Ov055_OpenSecondarySubObjects(int p);
extern int data_ov055_020b7740;
extern int gOv055DemyxLiE2PackPath;

void Ov055_InitGlobalRecordAndForward(void) {
    int d = data_ov055_020b7740;
    int base = d + 0x2d94;
    *(int *)(base + 0x14) = 0;
    RegisterSeqAndInit(base + 0x18, (int)&gOv055DemyxLiE2PackPath, 1, *(unsigned char *)(d + 9) + 7);
    Ov055_OpenSecondarySubObjects(d);
}
