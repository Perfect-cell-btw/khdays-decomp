typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad_0000[8];
    u8 display_state[0x94ec];
    void *scene_resources;
} Ov006RootContext;

extern Ov006RootContext *data_ov008_02090fa4;

extern void Ov008_SetBgLayout(void *resources);
extern void Ov008_UploadTextCells(void *resources);
extern void Ov008_RebindBgLayers(void *resources);
extern void Ov008_Menu_SetupSprites(void *resources);
extern void Ov008_SweepElements(void *display_state);
extern void Ov008_MissionBuildScreenCells(void *resources);
extern void SetMasterBrightnessMain(int brightness);
extern void SetMasterBrightnessSub(int brightness);
extern void Ov008_MissionRequestStateChange(int state, int arg1, int arg2, int arg3, int arg4);

static inline void SetMainVisiblePlanes(int planes) {
    volatile u32 *display_control = (volatile u32 *)0x04000000;
    *display_control = (*display_control & ~0x1f00) | (planes << 8);
}

static inline void SetSubVisiblePlanes(int planes) {
    volatile u32 *display_control = (volatile u32 *)0x04001000;
    *display_control = (*display_control & ~0x1f00) | (planes << 8);
}

void Ov008_MissionShutdownDisplayResources(void) {
    volatile u16 *main_palette = (volatile u16 *)0x05000000;

    SetMainVisiblePlanes(0);
    SetSubVisiblePlanes(0);
    Ov008_SetBgLayout(data_ov008_02090fa4->scene_resources);
    Ov008_UploadTextCells(data_ov008_02090fa4->scene_resources);
    Ov008_RebindBgLayers(data_ov008_02090fa4->scene_resources);
    Ov008_Menu_SetupSprites(data_ov008_02090fa4->scene_resources);
    Ov008_SweepElements(data_ov008_02090fa4->display_state);
    Ov008_MissionBuildScreenCells(data_ov008_02090fa4->scene_resources);

    main_palette[0] = 0;
    main_palette[0x200] = 0;
    SetMasterBrightnessMain(-16);
    SetMasterBrightnessSub(-16);
    Ov008_MissionRequestStateChange(0xe, 0, 0, 0, 0);
}
