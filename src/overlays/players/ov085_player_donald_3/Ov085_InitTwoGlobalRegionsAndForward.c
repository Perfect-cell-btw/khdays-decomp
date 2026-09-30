/* Initialises the character's effect record: clears its state, registers its effect sequence for
 * the owner's palette slot and creates the sub-object. */

extern void RegisterSeqAndInit(int a, int b, int c, int d);
extern void Ov085_CreateSubObject(int p);
extern int data_ov085_020b9260;
extern int gOv085DonaldLiE1PackPath;

void Ov085_InitTwoGlobalRegionsAndForward(void) {
    int d = data_ov085_020b9260;
    char *a = (char *)(d + 0x2000);
    char *b = (char *)(d + 0x2c50);
    *(int *)(a + 0xc50) = 0;
    *(int *)(b + 0x10) = 0;
    RegisterSeqAndInit((int)(b + 0x14), (int)&gOv085DonaldLiE1PackPath, 1, *(unsigned char *)(d + 9) + 7);
    Ov085_CreateSubObject(d);
}
