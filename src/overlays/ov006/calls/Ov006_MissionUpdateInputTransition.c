typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 field_0;
    u32 raw_keys;
    u16 packed_keys;
} MissionKeyBlock;

typedef struct {
    u32 mode;
    u32 keycode;
    u32 raw_keys;
    u16 packed_keys;
} MissionDisplayConfig;

typedef struct {
    u8 pad_000[0x28];
    u32 transition_requested;
    u8 pad_02c[0x3e8];
    u8 selection_block[0x18];
    MissionKeyBlock key_block;
    u8 pad_438[0x68];
    u32 active_value;
    u8 pad_4a4[0x44];
    u32 exit_requested;
} MissionContext;

extern MissionContext *data_ov006_020565e4;

extern void Ov105_WH_SetReceiver(void *callback);
extern void ReleaseServiceInstance(void);
extern void func_02031600(void *config);
extern void EnsureServiceInstance(void);
extern int func_01ff8128(void);
extern void Ov006_MissionPushDisplayConfig(void);
extern void StoreGlobalPtrArray4At0c(int slot, void *callback);
extern void Ov006_MissionApplyEntryUpdate(void);

void Ov006_MissionUpdateInputTransition(void) {
    MissionDisplayConfig exit_config;
    MissionDisplayConfig key_config;
    MissionKeyBlock *key_block;

    data_ov006_020565e4->transition_requested = 0;
    if (data_ov006_020565e4->exit_requested == 0) {
        Ov105_WH_SetReceiver(0);
    }
    ReleaseServiceInstance();

    if (data_ov006_020565e4->exit_requested != 0) {
        exit_config.mode = 1;
        exit_config.keycode = 1;
        func_02031600(&exit_config);
        EnsureServiceInstance();
    } else {
        if (func_01ff8128() == 0) {
            Ov006_MissionPushDisplayConfig();
        } else {
            key_block = &data_ov006_020565e4->key_block;
            Ov006_MissionPushDisplayConfig();
            key_config.mode = 3;
            key_config.raw_keys = key_block->raw_keys;
            key_config.packed_keys = key_block->packed_keys;
            func_02031600(&key_config);
        }
        EnsureServiceInstance();
        StoreGlobalPtrArray4At0c(0xd, Ov006_MissionApplyEntryUpdate);
    }

    data_ov006_020565e4->active_value = 1;
}
