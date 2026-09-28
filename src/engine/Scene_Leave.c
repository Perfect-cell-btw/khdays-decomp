#pragma thumb on
/* Scene_Leave -- leave the current scene, MAIN. The main screen falls back to BG0 only; in mode
 * bit 3 the effect layer is reset (SetGameMode(2)). Unless a reset is pending (data_0204c240 bit
 * 2 while mode bit 1 is set), the saved state of the game heap is restored: SetupTimer0Reload with
 * +0x0/+0x4, the random seed from +0x8, sound stopped, and the +0xc4 track released when no
 * +0xe0 object holds it. In mode bit 1 the sound fades out (InvokeSubStructAndStampByte(0x7f, 10)). A +0xdc
 * scene drops its +0xe0 object; the scene state (+0xc8) becomes 5 and Gfx_RestoreAfterPause is queued as
 * the next task. */
typedef unsigned char u8;
typedef unsigned int u32;

#define REG_DISPCNT (*(volatile u32 *)0x04000000)

typedef struct GameHeap {
    int saveA;                          /* +0x00 */
    int saveB;                          /* +0x04 */
    unsigned int seed;                  /* +0x08 */
    char pad0c[0xc4 - 0xc];
    int track;                          /* +0xc4 */
    int state;                          /* +0xc8 */
    char padcc[0xdc - 0xcc];
    int scene;                          /* +0xdc */
    int object;                         /* +0xe0 */
} GameHeap;

extern char *data_0204be08;
extern u8 data_0204c240;
extern char data_02042748[16];
extern int LoadGlobalU16At0(void);
extern void SetGameMode(int mode);
extern void SetupTimer0Reload(int a, int b);
extern void func_02001020(unsigned int seed);
extern void SNDi_BroadcastChannelOp(int op);
extern void SoundMgr_StartStream(int a);
extern void InvokeSubStructAndStampByte(int volume, int frames);
extern int Touch_StartAutoSampling(void);
extern void Ov002_HoldPanelScreen(int a, int object);
extern void RegisterNamedTask(int nSlot, const char *pName, void (*pfnTask)(void));
extern void Gfx_RestoreAfterPause(void);

void Scene_Leave(void)
{
    GameHeap *heap = (GameHeap *)(&data_0204be08)[1];

    REG_DISPCNT = (REG_DISPCNT & 0xffffe0ff) | 0x100;
    if ((LoadGlobalU16At0() & 8) != 0) {
        SetGameMode(2);
    }
    if ((data_0204c240 & 4) == 0 || (LoadGlobalU16At0() & 2) == 0) {
        SetupTimer0Reload(heap->saveA, heap->saveB);
        func_02001020(heap->seed);
        SNDi_BroadcastChannelOp(0);
        if (heap->object == 0 && heap->track != -1) {
            SoundMgr_StartStream(0);
        }
        heap->track = -1;
    }
    if ((LoadGlobalU16At0() & 2) != 0) {
        InvokeSubStructAndStampByte(0x7f, 10);
    }
    if (heap->scene != 0) {
        Touch_StartAutoSampling();
        Ov002_HoldPanelScreen(0, heap->object);
        heap->object = 0;
    }
    heap->state = 5;
    RegisterNamedTask(1, data_02042748, Gfx_RestoreAfterPause);
}
