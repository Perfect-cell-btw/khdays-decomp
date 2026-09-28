/* Scene entry for ov005's big context: 0x62198 bytes (401,816), measured off the
 * MI_CpuFill8 rather than inferred from the fields.
 *
 * Carries the saved mode byte over from the config block at
 * data_ov005_0205b85c+0x5c -- the same block Ov005_EnterSceneWithMode reads its
 * nOption64 from, which is why both files declare the one Ov005Config type.
 *
 * The closing `llStartTick = OS_GetTick()` is a single 64-bit store: the ROM
 * splits it into two str because GetTick64 returns the pair in r0:r1, and the
 * pool load for the return value is scheduled between them.
 *
 * The global is re-read at every use instead of being cached in a local -- that
 * is what the ROM does and caching it costs the match. */
typedef struct {
    char pad00[0x4bf4];
    long long llStartTick;      /* +0x4bf4 */
    char pad4bfc[0x94];
    int nUnk4c90;               /* +0x4c90 */
    char pad4c94[0x5d4e4];
    unsigned char bMode;        /* +0x62178 */
    char pad62179[0xf];
    int aSub62188[1];           /* +0x62188 */
} Ov005Context;

typedef struct {
    char pad00[0x5c];
    unsigned char bMode;    /* +0x5c */
    char pad5d[7];
    int nOption64;          /* +0x64 */
} Ov005Config;

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *dst, unsigned char value, unsigned int size);
extern void Ov005_InitWithDefaultHandlers(int *sub, int *out);
extern void Ov005_InitializeResultResources(void);
extern void Ov005_InitializeRewardItems(void);
extern void Ov005_LoadItemTextures(void);
extern void Ov005_LoadResultBackground(void);
extern void Ov005_InitializeResourceTracker(void);
extern void Ov005_InitializeResultSprites(void);
extern void Ov005_InitializeResultTextSurfaces(void);
extern void Ov005_InitRowSelection(int *p);
extern void Ov005_InvokeTagCallback(int a);
extern void Ov005_RenderTextSurface(int a);
extern long long OS_GetTick(void);
extern void Ov005_UpdateMainScene(void);

extern Ov005Context *data_ov005_0205b80c;
extern Ov005Config data_ov005_0205b85c;

void *Ov005_EnterMainScene(void) {
    int out[2] = { 0, 0 };

    data_ov005_0205b80c = NNSi_FndGetCurrentRootHeap();
    MI_CpuFill8(data_ov005_0205b80c, 0, 0x62198);
    data_ov005_0205b80c->bMode = data_ov005_0205b85c.bMode;
    Ov005_InitWithDefaultHandlers(data_ov005_0205b80c->aSub62188, out);
    Ov005_InitializeResultResources();
    Ov005_InitializeRewardItems();
    Ov005_LoadItemTextures();
    Ov005_LoadResultBackground();
    Ov005_InitializeResourceTracker();
    Ov005_InitializeResultSprites();
    Ov005_InitializeResultTextSurfaces();
    Ov005_InitRowSelection(&data_ov005_0205b80c->nUnk4c90);
    Ov005_InvokeTagCallback(0);
    Ov005_InvokeTagCallback(1);
    Ov005_RenderTextSurface(2);
    data_ov005_0205b80c->llStartTick = OS_GetTick();
    return (void *)&Ov005_UpdateMainScene;
}
