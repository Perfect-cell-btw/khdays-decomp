extern int GetEntryField20ByIndex(int idx);
extern int data_0204c3d8;

struct Row02087630 {
    char pad0[0x24];
    char b0 : 1;
    char b1 : 1;
    char brest : 6;
    unsigned char b25;
    signed char b26;
    char pad27;
    int w28;
    int w2c;
    char pad30[0x14];
};

void Ov022_MarshalEntrySnapshot(int idx) {
    int src = GetEntryField20ByIndex(idx);
    struct Row02087630 *e = (struct Row02087630 *)&data_0204c3d8 + idx;
    e->b0 = (*(unsigned long long *)(src) & 0x4000000000LL) != 0;
    e->b1 = (*(unsigned long long *)(src) & 0x2000000000LL) != 0;
    e->b25 = *(unsigned char *)(src + 0x2bb0);
    e->b26 = *(signed char *)(src + 0x2770);
    e->w28 = *(int *)(src + 0x2778);
    e->w2c = *(int *)(src + 0x2774);
}
