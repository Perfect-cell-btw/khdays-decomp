/* Initialises the charge effect record: clears it and registers its sequence for the owner's
 * palette slot. */

extern void RegisterSeqAndInit(int a, int b, int c, int d);
extern int gOv036DemyxEfWaPackPath;

void Ov036_InitRegionRecordAndZero(int this_) {
    char *a = (char *)(this_ + 0x2000);
    char *b = (char *)(this_ + 0x2c80);
    *(int *)(a + 0xc80) = 0;
    RegisterSeqAndInit((int)(b + 0xc), (int)&gOv036DemyxEfWaPackPath, 1, *(unsigned char *)(this_ + 9) + 7);
    *(int *)(b + 4) = 0;
    *(int *)(b + 8) = 0;
}
