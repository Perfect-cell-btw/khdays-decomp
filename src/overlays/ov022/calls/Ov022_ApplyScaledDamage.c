extern int Session_GetLocalPlayerIndex(void);
extern void Ov022_ApplyDamageAndFlagHit(int obj, int v, int mode);
extern int data_0204c678;

struct Row02093860 { char pad0[0xe]; unsigned short rate; char pad10[0x104 - 0x10]; };

void Ov022_ApplyScaledDamage(int arg0, int arg1, int arg2) {
    int q, prod;
    if (Session_GetLocalPlayerIndex() != 0) return;
    q = (((struct Row02093860 *)&data_0204c678)[*(unsigned char *)(arg0 + 9)].rate << 0xc) / 100;
    if (arg2 > 0) arg1 = arg2 * 10 + arg1;
    prod = q * arg1;
    if (*(unsigned short *)(arg0 + 0x12) == 0) return;
    Ov022_ApplyDamageAndFlagHit(arg0, (prod + 0xfff) >> 0xc, 0);
    *(unsigned long long *)(arg0 + 0x46c) |= 0x10000000000LL;
}
