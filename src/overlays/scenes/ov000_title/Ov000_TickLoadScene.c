/* Load-scene tick. Polls the pending resource load (Obj_IsIdFree); while it is not ready, returns 0
 * to stay in this scene. Once Ov000_UpdateLoadState reports phase 2, reads the two score halves
 * (0xc77/0xc87 via GameState_GetField), packs them (low | high<<16), keeps the best packed value
 * and its phase, advances loadPhase and -- at phase 3 -- finishes: snapshots the game state into
 * data_0204be18, counts the valid save slots, allocates and clears three 0x800 transfer buffers,
 * runs the four sub-initialisers, kicks the tween pulse, stamps a 64-bit timestamp, picks
 * selectedResult (0 when resultFlags set, else bestPhase), and returns the next scene callback
 * Ov000_TickSelectionScene. */

typedef unsigned char     u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef void (*OverlayCallback)(void);

typedef struct GameState {
    u32 words[0x72b];
} GameState;

typedef struct Ov000LoadSlot {
    int status;
    u8 pad_0004[0x1c];
} Ov000LoadSlot;

typedef struct Ov000LoadSceneContext {
    u8 pad_0000[0x4ace];
    u8 selectedMode;
    u8 pad_4acf[0x0d];
    int loadPhase;
    u32 reserved4ae0;
    u32 timestampLow;
    u32 timestampHigh;
    void *transferBuffers[3];
    u8 pad_4af8[3];
    u8 loadState;
    u8 pad_4afc[8];
    void *loadResource;
    int selectedResult;
    u8 pad_4b0c[0x14];
    Ov000LoadSlot slots[3];
    u8 pad_4b80[0x1f4];
    u8 tweenPulse[0x24];
    GameState gameStateSnapshot;
    u8 pad_6a44[4];
    signed int resultFlags : 16;
    unsigned int resultFlagsRest : 16;
    int validSlotCount;
    u8 pad_6a50[0x0c];
    int bestPhase;
    u32 bestPackedValue;
} Ov000LoadSceneContext;

extern Ov000LoadSceneContext *data_ov000_0205ac24;
extern GameState *data_0204be18;

extern int Obj_IsIdFree(void *resource);
extern u8 Ov000_UpdateLoadState(int phase);
extern int GameState_GetField(int field, int kind);
extern void *NNS_FndAllocFromDefaultExpHeapEx(u32 size, int alignment);
extern void MIi_CpuClear16(u16 value, void *destination, u32 size);
extern void Ov000_LoadPageSubScreenLayer(void);
extern void Ov000_LayoutSelectionPages(void);
extern void Ov000_BuildPageTextSurfaces(void);
extern void Ov000_UpdateNumberDisplays(void);
extern void Tween_Clear(void *tween);
extern u64 OS_GetTick(void);
extern void Ov000_PlaceCursorByMode(int enabled, int mode);
extern void Ov000_TickSelectionScene(void);

OverlayCallback Ov000_TickLoadScene(void)
{
    int ready = 0;
    Ov000LoadSceneContext *context;

    context = data_ov000_0205ac24;
    if (Obj_IsIdFree(context->loadResource) == 0) {
        return 0;
    }

    context = data_ov000_0205ac24;
    if (Ov000_UpdateLoadState(context->loadPhase) == 2) {
        int high = GameState_GetField(0xc77, 0x10);
        int low = GameState_GetField(0xc87, 0x10);
        u32 packed = low | (high << 16);

        if (packed > data_ov000_0205ac24->bestPackedValue) {
            data_ov000_0205ac24->bestPackedValue = packed;
            data_ov000_0205ac24->bestPhase =
                data_ov000_0205ac24->loadPhase;
        }

        data_ov000_0205ac24->loadPhase =
            data_ov000_0205ac24->loadPhase + 1;
        data_ov000_0205ac24->loadState = 0;
        if (data_ov000_0205ac24->loadPhase >= 3) {
            ready = 1;
        }
    }

    if (ready != 0) {
        context = data_ov000_0205ac24;
        *data_0204be18 = context->gameStateSnapshot;

    context->validSlotCount = 0;
    {
        int i;

        for (i = 0; i < 3; i++) {
            context = data_ov000_0205ac24;
            if (context->slots[i].status > 0) {
                context->validSlotCount++;
            }
        }
    }

    {
        int i;

        for (i = 0; i < 3; i++) {
            data_ov000_0205ac24->transferBuffers[i] =
                NNS_FndAllocFromDefaultExpHeapEx(0x800, 2);
            MIi_CpuClear16(
                0, data_ov000_0205ac24->transferBuffers[i], 0x800);
        }
    }

    Ov000_LoadPageSubScreenLayer();
    Ov000_LayoutSelectionPages();
    Ov000_BuildPageTextSurfaces();
    Ov000_UpdateNumberDisplays();

    Tween_Clear(data_ov000_0205ac24->tweenPulse);
    context = data_ov000_0205ac24;
    {
        u64 tick = OS_GetTick();

        context->timestampLow = (u32)tick;
        context->timestampHigh = (u32)(tick >> 32);
    }

    {
        int selected;

        selected =
            context->resultFlags != 0 ? 0 : context->bestPhase;
        context->selectedResult = selected;
    }

    data_ov000_0205ac24->selectedMode =
        (u8)data_ov000_0205ac24->selectedResult;
    Ov000_PlaceCursorByMode(1, data_ov000_0205ac24->selectedResult);
        return Ov000_TickSelectionScene;
    }
    return 0;
}
