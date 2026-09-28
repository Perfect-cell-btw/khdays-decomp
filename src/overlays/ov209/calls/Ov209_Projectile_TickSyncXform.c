extern int Ov107_ProcessObjectTick();

struct s44 {
    int a[11];
};

struct s16 {
    int a[4];
};

struct obj {
    char pad0[0x64];
    struct s16 src2;
    char pad1[0xa0 - 0x64 - 0x10];
    struct s44 src1;
    char pad2[0x388 - 0xa0 - 0x2c];
    char **p388;
};

void Ov209_Projectile_TickSyncXform(struct obj *o)
{
    Ov107_ProcessObjectTick(o);
    *(struct s44 *)(*(o->p388) + 0x10) = o->src1;
    *(struct s16 *)(*(o->p388) + 0x58) = o->src2;
    *(struct s16 *)(*(o->p388) + 0x68) = o->src2;
}
