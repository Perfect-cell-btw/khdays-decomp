typedef unsigned char u8;
typedef short s16;

typedef struct {
    u8 pad0000[0x69c];
    int nField069c;                 /* +0x69c */
    u8 pad06a0[0xc];
    int nRowY;                      /* +0x6ac */
    u8 pad06b0[0x20];
    int nOriginX;                   /* +0x6d0 */
    u8 pad06d4[0x108];
    int nCursor;                    /* +0x7dc */
} Ov002CursorCtx;

extern int data_ov002_0207f624;

extern int Ov002_Ctx_FindActiveEntryByTag(int nTag);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_6(int nNode, int nArg);
extern int Ov002_ForwardToSubDc(int nTag);
extern void Ov002_PositionSubDcHandle_2(int nObj, int y, int x);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int nObj);
extern void Ov002_PositionSubDcHandle_4(int nNode, int y, int x);
extern void Ov002_ForwardToSubDc_3(int nNode);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(int nNode, int bArmed);

void Ov002_MoveCursorTo(int index) {
    Ov002CursorCtx *ctx = (Ov002CursorCtx *)data_ov002_0207f624;
int nNode;
    int nObj;
    s16 y;
    s16 x;

    nNode = Ov002_Ctx_FindActiveEntryByTag(0xd);
    Ov002_Ctx_SetTagTrackerNodeArmed_6(nNode, ctx->nField069c);
    y = (s16)ctx->nRowY;
    x = (s16)(ctx->nOriginX + index * 2);
    nObj = Ov002_ForwardToSubDc(0x86);

    if (index >= 0) {
        Ov002_PositionSubDcHandle_2(nObj, y, (s16)(ctx->nOriginX + ctx->nCursor * 2));
        Ov002_Ctx_InvokeTagTrackerCallback(nObj);
        Ov002_PositionSubDcHandle_4(nNode, y, x);
        Ov002_ForwardToSubDc_3(nNode);
    } else {
        Ov002_Ctx_SetTagTrackerNodeArmed_5(nNode, 0);
    }

    ctx->nCursor = index;
}
