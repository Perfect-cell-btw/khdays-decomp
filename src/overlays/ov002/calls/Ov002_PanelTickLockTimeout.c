/* Expire the lock at +0x5dc once it has been held longer than the timeout. */
extern unsigned long long OS_GetTick(void);

typedef struct {
    char pad0000[1];
    unsigned char bMode;            /* +0x1 */
    char pad0002[0x5d6];
    int bHeld;                      /* +0x5d8 */
    int nOwner;                     /* +0x5dc, 0 = free */
    unsigned long long qwTakenAt;   /* +0x5e0 */
} Ov002LockContext;

extern Ov002LockContext *data_ov002_0207f620;

extern int Ov002_ForwardToSubDc(int nId);
extern void Ov002_ForwardToSubDc_2(int nEntry);
extern void Ov002_ClearRequest9Blocks(void);
extern void Ov002_SelectEntry(int nId);

int Ov002_PanelTickLockTimeout(void) {
    Ov002LockContext *ctx = data_ov002_0207f620;

    if (ctx->bHeld != 0) {
        if (ctx->qwTakenAt + 0x17f898 < OS_GetTick()) {
            Ov002_ForwardToSubDc_2(Ov002_ForwardToSubDc(0x4e));
            Ov002_ForwardToSubDc_2(Ov002_ForwardToSubDc(0x48));
            Ov002_ClearRequest9Blocks();
            ctx->bHeld = 0;
            ctx->nOwner = 0;
        }
    }

    if (ctx->bMode == 9) {
        Ov002_SelectEntry(0xb);
    }
    return 0;
}
