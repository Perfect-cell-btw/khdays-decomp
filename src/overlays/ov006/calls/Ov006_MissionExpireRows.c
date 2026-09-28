typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 field_00[0xf];
    u16 item_count;
    u16 field_3e;
    u16 ready;
    u16 field_42;
    u32 field_44[0x1f];
} MissionRecord;

typedef struct {
    u8 pad_000[0x100];
    volatile u8 row_count;
    u8 pad_101[3];
    MissionRecord rows[4];
    u32 row_states[4];
} MissionContext;

typedef struct {
    MissionContext *context;
    void *controller_instance;
} MissionGlobals;

extern MissionGlobals data_ov006_020565e4;
extern u8 data_ov006_020561c8[];
extern int Game_PollSceneAlive(void);
extern void Ov105_SetParamWord8(u32 value);
extern void Ov105_WH_StartScan(void (*callback)(const MissionRecord *),
                                void *data, int value);
extern void func_01ff80a8(void);
extern void Ov006_MissionUpsertRowByKey(const MissionRecord *record);
extern void Ov006_MissionDriveSound(void);

void *Ov006_MissionExpireRows(void) {
    switch (Game_PollSceneAlive()) {
    case 1:
        Ov105_SetParamWord8(0x800356);
        Ov105_WH_StartScan(Ov006_MissionUpsertRowByKey,
                            data_ov006_020561c8, 0);
        break;

    case 2: {
        u8 i;

        func_01ff80a8();
        for (i = 0; i < data_ov006_020565e4.context->row_count; i++) {
            u8 j;

            if (data_ov006_020565e4.context->row_states[i] < 600) {
                data_ov006_020565e4.context->row_states[i]++;
            }

            if (data_ov006_020565e4.context->row_states[i] >= 600) {
                for (j = i;
                     j < data_ov006_020565e4.context->row_count - 1;
                     j++) {
                    data_ov006_020565e4.context->rows[j] =
                        data_ov006_020565e4.context->rows[j + 1];
                }
                data_ov006_020565e4.context->row_count--;
                i--;
            }
        }
        break;
    }

    case 3:
        break;

    default:
        Ov006_MissionDriveSound();
        break;
    }

    return 0;
}
