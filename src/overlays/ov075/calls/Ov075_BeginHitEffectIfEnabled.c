extern int Session_GetLocalPlayerIndex(void);
extern void Slot_Spawn(int a, int b, int c, int d);
extern int data_ov075_020b9e20;

typedef struct { unsigned char b0 : 1; } Flags;

int Ov075_BeginHitEffectIfEnabled(int *ctx, char *node) {
    int base = *(int *)&data_ov075_020b9e20;
    int obj = ctx[2];
    unsigned short f;
    f = 0;
    node[2] = 4;
    *(int *)(node + 4) = 0x3000;
    if (*(unsigned char *)(base + 8) == Session_GetLocalPlayerIndex()) {
        if ((*(int *)base & 0x10000) == 0) {
            f |= 1;
        }
    }
    if (ctx[0] == 1) {
        if (((Flags *)(obj + 0x694))->b0) {
            Slot_Spawn(0xcc, 0, (int)(node + 0xcc), f);
        }
    } else if (ctx[0] == 2) {
        if (((Flags *)(obj + 0x694))->b0) {
            Slot_Spawn(0xcc, 1, (int)(node + 0xcc), f);
        }
    }
    return 0;
}
