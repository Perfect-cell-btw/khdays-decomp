/*
 * Ov002_RequestPageRetry - go round again, now or as soon as it can.
 *
 * The sibling of the advance request: it only applies once the page is closing,
 * and it queues the retry step behind the same handover slot when the screen or
 * the caption is not ready for it yet.
 *
 * ARM.
 */

typedef struct {
    char pad000[4];
    int bClosing;
    char pad008[0x30];
    void (*pfnDone)(void);
} Ov002PageContext;

extern Ov002PageContext *data_ov002_0207f634;

extern int Ov002_CancelQueuedLoads(void);
extern int Ov002_RequestCaption(int nMode, int nTake);
extern void Ov002_ArmHudTagGroup(void);
extern int Ov002_RunShutdownHook(void);

void Ov002_RequestPageRetry(void)
{
    Ov002PageContext *ctx;

    ctx = data_ov002_0207f634;
    if (ctx->bClosing == 0) {
        return;
    }
    if (ctx->pfnDone != 0) {
        return;
    }
    if (Ov002_RunShutdownHook() != 0) {
        return;
    }

    if (Ov002_CancelQueuedLoads() != 0 && Ov002_RequestCaption(1, 0) != 0) {
        Ov002_ArmHudTagGroup();
    } else {
        ctx->pfnDone = Ov002_ArmHudTagGroup;
    }
}
