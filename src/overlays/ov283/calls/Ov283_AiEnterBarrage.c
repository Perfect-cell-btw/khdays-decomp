typedef struct { int a, b, c; } Blk12;

typedef struct {
    int p0;
    char pad1[4];
    int f8;
    char pad2[4];
    Blk12 blk;
    char pad3[0x2c];
    int f48;
    char pad4[0x1c];
    int f68;
    int f6c;
    char pad5[4];
    int f74;
} Ctx;

typedef struct {
    int field_00;
    Ctx *ctx;
} Self;

extern int Ov283_PostItemUpdate(int, int, int, int);
extern int Ov107_PostTagUpdate(int, int, int);
extern void SetIndexedSlot(int *a, int i, int v);
extern Blk12 data_02041dc8;
extern void Ov283_VolleyCloseTick(void);

void Ov283_AiEnterBarrage(Self *self) {
    Ctx *ctx = self->ctx;

    Ov283_PostItemUpdate(ctx->p0, 0x173, 7, ctx->f8);
    Ov107_PostTagUpdate(ctx->p0, 9, 0);

    ctx->f68 = 0;
    ctx->f6c = 0;
    ctx->f48 = 0;
    ctx->blk = data_02041dc8;
    ctx->f74 = 0;

    SetIndexedSlot((int *)self, *(signed char *)((char *)self + 0x20), (int)Ov283_VolleyCloseTick);
}
