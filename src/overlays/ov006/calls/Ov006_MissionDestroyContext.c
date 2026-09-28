typedef unsigned char u8;

typedef struct {
    u8 first;
    u8 pad_01[0x0b];
    u8 second;
    u8 pad_0d[0x3f];
} MissionCleanupBlock;

typedef struct {
    void *primary_resource;
    void *secondary_resource;
    u8 work_object;
    u8 pad_0009[0x4b];
    u8 scene_object;
    u8 pad_0055[0x461f];
    int scene_active;
    u8 pad_4678[0x414];
    u8 renderer;
    u8 pad_4a8d[0x461f];
    int renderer_active;
    u8 pad_90b0[0x41c];
    void *work_buffers[8];
    u8 pad_94ec[0x274];
    MissionCleanupBlock cleanup_blocks[2];
} Ov006RootContext;

extern Ov006RootContext *data_ov006_02056664;
extern void Slot_UnlinkAll(void *object);
extern void Obj_Release(void *object);
extern void Ov006_SweepElements(void *object);
extern void Ov006_ReleaseThreeBuffers(void *object);
extern void FontResource_Destroy(void *object);
extern void TileTextRenderer_Destroy(void *object);
extern void ZeroHalfThenFree(void *resource);
extern void MIi_CpuClear16(int value, void *destination, unsigned size);
extern void NNSi_FndFreeFromDefaultHeap(void *memory);

void Ov006_MissionDestroyContext(void) {
    u8 i;

    if (data_ov006_02056664->scene_active != 0) {
        Slot_UnlinkAll(&data_ov006_02056664->scene_object);
        Obj_Release(&data_ov006_02056664->scene_object);
    }

    if (data_ov006_02056664->renderer_active != 0) {
        Slot_UnlinkAll(&data_ov006_02056664->renderer);
        Obj_Release(&data_ov006_02056664->renderer);
    }

    Ov006_SweepElements(&data_ov006_02056664->work_object);
    Ov006_ReleaseThreeBuffers(&data_ov006_02056664->work_object);
    FontResource_Destroy(&data_ov006_02056664->cleanup_blocks[1].first);
    FontResource_Destroy(&data_ov006_02056664->cleanup_blocks[0].first);
    TileTextRenderer_Destroy(&data_ov006_02056664->cleanup_blocks[1].second);
    TileTextRenderer_Destroy(&data_ov006_02056664->cleanup_blocks[0].second);
    ZeroHalfThenFree(data_ov006_02056664->primary_resource);

    if (data_ov006_02056664->secondary_resource != 0) {
        ZeroHalfThenFree(data_ov006_02056664->secondary_resource);
    }

    for (i = 0; i < 8; i++) {
        MIi_CpuClear16(0, data_ov006_02056664->work_buffers[i], 0x600);
        if (data_ov006_02056664->work_buffers[i] != 0) {
            NNSi_FndFreeFromDefaultHeap(data_ov006_02056664->work_buffers[i]);
            data_ov006_02056664->work_buffers[i] = 0;
        }
    }

    data_ov006_02056664 = 0;
}
