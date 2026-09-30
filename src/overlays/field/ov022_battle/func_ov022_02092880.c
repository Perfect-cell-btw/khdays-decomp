/* Loads a level's four values (clamped to level 9) from the battle table file into the record and
 * marks it loaded. */

extern int Archive_LoadFile(void *arg0, int arg1, int arg2, int arg3);
extern void NNSi_FndFreeFromDefaultHeap(int arg0);
extern int gOv022BaChDrPath;

void func_ov022_02092880(unsigned char *arg0, int arg1, int arg2, int arg3) {
    if (0 < arg1) {
        int x = Archive_LoadFile(&gOv022BaChDrPath, 6, arg2, arg3);
        int base;
        if (9 < arg1) arg1 = 9;
        base = x + (arg1 - 1) * 8;
        *(unsigned short *)(arg0 + 2) = *(unsigned short *)base;
        *(unsigned short *)(arg0 + 4) = *(unsigned short *)(base + 2);
        *(unsigned short *)(arg0 + 6) = *(unsigned short *)(base + 4);
        *(unsigned short *)(arg0 + 8) = *(unsigned short *)(base + 6);
        NNSi_FndFreeFromDefaultHeap(x);
        *arg0 = *arg0 | 1;
    }
}
