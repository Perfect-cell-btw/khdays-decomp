/* Ov274_AiSpawnEffectOnIdle -- reset the tuning, quiesce the owner and queue the effect, then hand on.
 * The constants at data_02041dc8 are copied into +0x14 unconditionally. Nothing further happens
 * while the gate byte at *(+0xc) is set.
 * Otherwise the owner is quiesced (mode 3), the progress fields (+0x24/+0x52) cleared, and a
 * 4-byte descriptor is queued through func_02031384 -- built from data_ov274_020d41ec's +4/+6,
 * except the low half is then overwritten with the owner's own id (+2), so only the high half of
 * the global actually survives. Finally the caller's action (+0x20) is dispatched through
 * SetIndexedSlot with Ov274_FallTick as the continuation. */

typedef struct {
    int x;
    int y;
    int z;
} Vec3;

typedef struct {
    unsigned short lo;
    unsigned short hi;
} Ov206_EffectDesc;

extern void Ov107_PostTagUpdate(int owner, int mode, int arg);
extern void func_02031384(int a, Ov206_EffectDesc *desc, int n, int v);
extern void SetIndexedSlot(int self, int action, void (*cb)(void));
extern void Ov274_FallTick(void);
extern Vec3 data_02041dc8;
extern unsigned short data_ov274_020d41ec[];

void Ov274_AiSpawnEffectOnIdle(int self) {
    int *ctx;
    Ov206_EffectDesc desc;
    unsigned short id;

    ctx = *(int **)(self + 4);
    *(Vec3 *)((char *)ctx + 0x14) = data_02041dc8;
    if (**(unsigned char **)(ctx + 3) != 0) {
        return;
    }

    Ov107_PostTagUpdate(ctx[0], 3, 0);
    ctx[9] = 0;
    *(unsigned char *)((char *)ctx + 0x52) = 0;

    desc.hi = data_ov274_020d41ec[3];
    desc.lo = data_ov274_020d41ec[2];
    id = *(unsigned short *)(ctx[0] + 2);
    desc.lo = id;
    func_02031384(1, &desc, 4, id);

    SetIndexedSlot(self, *(signed char *)(self + 0x20), Ov274_FallTick);
}
