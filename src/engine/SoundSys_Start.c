#pragma thumb on

#include "nitro/types.h"
#include "game/engine.h"

typedef struct NNSSndHeap *NNSSndHeapHandle;
typedef struct { void *player; } NNSSndHandle;
typedef struct { void *player; } NNSSndStrmHandle;

#define SND_BANK_NUM 4
#define SND_BANK_SIZE 0x1c00

typedef struct SoundNode {
    struct SoundNode *next;             /* +0x00 */
    struct SoundNode *prev;             /* +0x04 */
    char pad08[0x16 - 8];
    u16 id;                             /* +0x16 */
    int pad18;
    NNSSndHandle handle;                /* +0x1c */
} SoundNode;

typedef struct SoundCtx {
    char arc[0x94];                                 /* +0x00000: NNSSndArc */
    void *waveHeap;                                 /* +0x00094 */
    void *waveHeapCur;                              /* +0x00098 */
    int waveState;                                  /* +0x0009c */
    char mainArea[0x5e400];                         /* +0x000a0 */
    char bankArea[SND_BANK_NUM][SND_BANK_SIZE];     /* +0x5e4a0 */
    char streamArea[0x4b000];                       /* +0x654a0 */
    NNSSndHeapHandle mainHeap;                      /* +0xb04a0 */
    NNSSndHeapHandle bankHeap[SND_BANK_NUM];        /* +0xb04a4 */
    NNSSndHeapHandle streamHeap;                    /* +0xb04b4 */
    char effectArea[0x4000];                        /* +0xb04b8 */
    NNSSndHeapHandle effectHeap;                    /* +0xb44b8 */
    NNSSndStrmHandle strm[2];                       /* +0xb44bc */
    NNSSndHandle seHandle;                          /* +0xb44c4 */
    NNSSndHandle bgmHandle;                         /* +0xb44c8 */
    int fade[3];                                    /* +0xb44cc */
    int scale;                                      /* +0xb44d8 */
    int pan[2];                                     /* +0xb44dc */
    SoundNode node[16];                             /* +0xb44e4 */
    SoundNode *freeNode;                            /* +0xb46e4 */
    int pad0b46e8;
    int volumeA;                                    /* +0xb46ec */
    int volumeB;                                    /* +0xb46f0 */
    u16 level;                                      /* +0xb46f4 */
    s16 curBgm;                                     /* +0xb46f6 */
    s16 nextBgm;                                    /* +0xb46f8 */
    u16 bgmFlags;                                   /* +0xb46fa */
    u8 muted;                                       /* +0xb46fc */
    u8 masterLevel;                                 /* +0xb46fd */
    char pad0b46fe[0xb4704 - 0xb46fe];
    u8 bankState[SND_BANK_NUM];                     /* +0xb4704 */
    u8 bankRefs[SND_BANK_NUM];                      /* +0xb4708 */
    s16 bankId[SND_BANK_NUM];                       /* +0xb470c */
    s8 idBank[0x8a];                                /* +0xb4714 */
    u8 seqState;                                    /* +0xb479e */
    char pad0b479f[0xb47b2 - 0xb479f];
    u8 flagA;                                       /* +0xb47b2 */
    u8 flagB;                                       /* +0xb47b3 */
    u8 flagC;                                       /* +0xb47b4 */
    u8 enabled;                                     /* +0xb47b5 */
    u8 busy;                                        /* +0xb47b6 */
    u8 pad0b47b7;
} SoundCtx;

extern SoundCtx *gSoundMgr;
extern const char gSndSoundDataPath[];      /* default sound archive path */
extern void NNS_SndPlayerStopSeqAll(int mode);
extern void NNS_SndInit(void);
extern void NNS_SndArcInit(void *arc, const char *path, NNSSndHeapHandle heap, int bSymbolLoad);   /* NNS_SndArcInit */
extern void NNS_SndArcSetLoadBlockSize(int prio);
extern void NNS_SndArcPlayerSetup(NNSSndHeapHandle heap);
extern void Word_Clear(NNSSndHandle *handle);           /* NNS_SndHandleInit */
extern void MI_CpuFill8(void *dest, int data, u32 size);
extern void NNS_SndArcStrmInit(u32 threadPrio, NNSSndHeapHandle heap);   /* NNS_SndArcStrmInit */
extern void Word_ClearB(NNSSndStrmHandle *handle);       /* NNS_SndStrmHandleInit */
extern int NNS_SndArcLoadBank(u32 waveId, NNSSndHeapHandle heap);
extern void *NNS_SndHeapSaveState(NNSSndHeapHandle heap);

/* SoundSys_Start -- start the sound system on a sound archive, MAIN. `path` (default
 * gSndSoundDataPath) is opened into the context's archive with the main heap; the player priority,
 * the main heap's groups and the SE/BGM handles are set up; the 16 sound nodes are cleared,
 * chained into a doubly linked free list (ids 6..21, each with its own handle); streaming starts
 * on the effect heap (priority 10) with its two stream handles; the BGM slots are emptied, wave
 * archive 0x25 is loaded and the main heap's current level is recorded twice with the wave state
 * reset to -1. */
void SoundSys_Start(const char *path)
{
    SoundCtx *ctx = gSoundMgr;
    int i;

    if (path == 0) {
        path = gSndSoundDataPath;
    }
    SoundMgr_WaitLoaderIfState1();
    NNS_SndPlayerStopSeqAll(0);
    NNS_SndInit();
    NNS_SndArcInit(ctx->arc, path, ctx->mainHeap, 0);
    NNS_SndArcSetLoadBlockSize(0x400);
    NNS_SndArcPlayerSetup(ctx->mainHeap);
    Word_Clear(&ctx->seHandle);
    Word_Clear(&ctx->bgmHandle);
    MI_CpuFill8(ctx->node, 0, sizeof(ctx->node));
    for (i = 0; i < 16; i++) {
        ctx->node[i].next = (i < 15) ? &ctx->node[i + 1] : 0;
        ctx->node[i].prev = (i > 0) ? &ctx->node[i - 1] : 0;
        ctx->node[i].id = i + 6;
        Word_Clear(&ctx->node[i].handle);
    }
    ctx->freeNode = &ctx->node[0];
    NNS_SndArcStrmInit(10, ctx->effectHeap);
    Word_ClearB(&ctx->strm[0]);
    Word_ClearB(&ctx->strm[1]);
    ctx->curBgm = -1;
    ctx->nextBgm = -1;
    ctx->bgmFlags = 0;
    NNS_SndArcLoadBank(0x25, ctx->mainHeap);
    ctx->waveHeap = NNS_SndHeapSaveState(gSoundMgr->mainHeap);
    ctx->waveHeapCur = ctx->waveHeap;
    ctx->waveState = -1;
}
