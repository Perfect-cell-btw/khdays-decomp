typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*MissionState)(void);

typedef struct {
    void *sceneObject;
    u8 inputHeaderAndPadding[0x1c];
    u32 sessionReady;
    u32 parametersReady;
    u32 singleRowMode;
    u32 menuState;
    u8 menuMetadata[8];
    u32 cursorIndex;
    u8 selectionAndRows[0x24];
    u8 resourceRegion[0x10];
} MissionMenuContext;

extern u16 data_ov006_020561d0[];
extern MissionMenuContext *data_ov006_02056660;
extern u8 data_ov006_0205652c[];
extern u8 data_ov006_02056508[];

extern MissionMenuContext *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern int GameState_IsFlagSet(u32 id);
extern int Header_InitWithLimits(void *header, short *limits);
extern void *InstantiateClass(void *descriptor, void *parameter);
extern void Ov006_StartWipeToSubState(int subState);
extern void Ov006_MissionEnsureController(int enabled);
extern int Ov006_TickInputUpdate(void);
extern int Session_Exists(void);
extern int Session_IsActive(void);
extern int Session_IsReady(void);
extern int Ov006_MissionPollKeys(void);
extern int Ov006_SetTitleMode(u32 mode);
extern void Ov006_FreeResourceRecordBuffer(void *subObject);
extern void Ov006_InitResourceRecord(void *subObject, const void *config);
extern void Ov006_MissionBuildOptionRows(void);
extern void Ov006_MissionMenuTick(void);

MissionState Ov006_CreateMissionMenu(int immediate)
{
    short limits[2];

    {
        char *source = (char *)data_ov006_020561d0;
        u16 upper = *(u16 *)(source + 12);
        u16 lower = *(u16 *)(source + 10);
        *(volatile u16 *)&limits[1] = upper;
        *(volatile u16 *)&limits[0] = lower;
    }
    MissionMenuContext *context = NNSi_FndGetCurrentRootHeap();
    data_ov006_02056660 = context;
    MI_CpuFill8(context, 0, sizeof(MissionMenuContext));
    data_ov006_02056660->cursorIndex = 0;
    data_ov006_02056660->singleRowMode =
        GameState_IsFlagSet(0x200d) != 0;
    data_ov006_02056660->menuState = 0;
    Header_InitWithLimits(
        &data_ov006_02056660->inputHeaderAndPadding, limits);

    MissionState nextState;
    if (immediate != 0) {
        data_ov006_02056660->sceneObject =
            InstantiateClass(data_ov006_0205652c, (void *)1);
        Ov006_StartWipeToSubState(0xd);
        Ov006_MissionEnsureController(1);
        data_ov006_02056660->sessionReady = 1;
        data_ov006_02056660->singleRowMode = Ov006_TickInputUpdate();
        nextState = Ov006_MissionBuildOptionRows;
    } else if (data_ov006_02056660->singleRowMode != 0 ||
               (Session_Exists() != 0 && Session_IsActive() != 0)) {
        data_ov006_02056660->sceneObject =
            InstantiateClass(data_ov006_0205652c, (void *)1);
        Ov006_MissionEnsureController(0);
        data_ov006_02056660->sessionReady = Session_IsReady();
        Ov006_SetTitleMode(Ov006_MissionPollKeys());
        Ov006_StartWipeToSubState(4);
        nextState = Ov006_MissionBuildOptionRows;
    } else {
        data_ov006_02056660->sceneObject =
            InstantiateClass(data_ov006_0205652c, (void *)0);
        Ov006_MissionEnsureController(0);
        Ov006_StartWipeToSubState(0);
        nextState = Ov006_MissionMenuTick;
    }

    Ov006_FreeResourceRecordBuffer(&data_ov006_02056660->resourceRegion);
    Ov006_InitResourceRecord(
        &data_ov006_02056660->resourceRegion, data_ov006_02056508);
    return nextState;
}
