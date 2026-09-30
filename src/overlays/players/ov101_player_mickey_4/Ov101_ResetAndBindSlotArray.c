/* Initialises the character's effect block: clears the states, registers the main effect and six
 * slot sequences for the owner's palette slot and creates the sub-object. */

extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern void Ov101_CreateSubObject(int base);
extern int data_ov101_020bc0e0;
extern int gOv101MickeyLiE0PackPath;
extern int gOv101MickeyLiE2PackPath;

void Ov101_ResetAndBindSlotArray(void) {
    int i;
    char *q;
    char *r;
    int j;
    int base = *(int *)&data_ov101_020bc0e0;
    char *p = (char *)(base + 0x2c80);
    *(int *)(p + 0x110) = 0;
    *(int *)(p + 0x11c) = 0;
    for (i = 0, q = p; i < 6; i++, q += 0x120) {
        *(int *)(q + 0x128) = 0;
    }
    RegisterSeqAndInit((int)(p + 4), &gOv101MickeyLiE0PackPath, 1, *(unsigned char *)(base + 9) + 7);
    for (j = 0, r = p + 0x12c; j < 6; j++, r += 0x120) {
        RegisterSeqAndInit((int)r, &gOv101MickeyLiE2PackPath, 1, *(unsigned char *)(base + 9) + 7);
    }
    Ov101_CreateSubObject(base);
}
