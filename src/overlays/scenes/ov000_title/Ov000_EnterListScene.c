/* Enters the list scene once the previous object is gone: sets up the 2D engines, graphics, menu
 * objects, surfaces and rows, starts touch sampling and the music, and starts the fade-in. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef void (*OverlayCallback)(void);

typedef struct {
    u8 pad_0000[0x84];
    void *resource;
    u8 pad_0088[0x95e2];
    u16 transition_state;
    u8 pad_966c[0x3aac];
    u8 transition_object[1];
} OverlayContext;

typedef struct {
    u8 pad_0000[0x9660];
    void *resource_9660;
} OverlaySharedContext;

extern OverlaySharedContext *data_ov000_0205ac3c;
extern u8 data_ov000_0205abe8[];
extern OverlayContext *NNSi_FndGetCurrentRootHeap(void);
extern int Obj_IsIdFree(void *resource);
extern void SetMasterBrightnessMain(int value);
extern void SetMasterBrightnessSub(int value);
extern void Ov000_InitializeListScene2dEngines(void);
extern void *Msg_OpenContainerAndReadHeader(const void *data, int id);
extern void Ov000_LoadListSceneGraphics(void);
extern void Ov000_SetupMenuObjects(void);
extern void Ov000_InitSceneSurfaces(void);
extern void Ov000_LoadPanelHandles(void);
extern void Ov000_FillListRows(void);
extern void Touch_StartAutoSampling(void);
extern void ZeroHalfThenFree(void *resource);
extern void Ov000_ReflowList(int value);
extern void Ov000_QueueResourceTransfers(void);
extern int SoundStrm_HasPlaybackPos(int value);
extern void StampByteAndInvokeSubStructAt(int first, int second);
extern void Tween_Configure(void *object, int x, int y, int scale, int duration);
extern void Tween_Start(void *object);
extern void Ov000_FadeTransitionTick(void);

OverlayCallback Ov000_EnterListScene(void) {
    OverlayContext *context = NNSi_FndGetCurrentRootHeap();

    if (Obj_IsIdFree(data_ov000_0205ac3c->resource_9660) == 0) {
        return 0;
    }

    SetMasterBrightnessMain(-16);
    SetMasterBrightnessSub(-16);
    Ov000_InitializeListScene2dEngines();
    context->resource = Msg_OpenContainerAndReadHeader(data_ov000_0205abe8, 14);
    Ov000_LoadListSceneGraphics();
    Ov000_SetupMenuObjects();
    Ov000_InitSceneSurfaces();
    Ov000_LoadPanelHandles();
    Ov000_FillListRows();
    Touch_StartAutoSampling();
    ZeroHalfThenFree(context->resource);
    Ov000_ReflowList(28);
    Ov000_QueueResourceTransfers();

    if (SoundStrm_HasPlaybackPos(0) == 0) {
        StampByteAndInvokeSubStructAt(0, 0);
    }

    Tween_Configure(context->transition_object, 0, 0, 0x1000, 500);
    Tween_Start(context->transition_object);
    context->transition_state = 3;
    return Ov000_FadeTransitionTick;
}
