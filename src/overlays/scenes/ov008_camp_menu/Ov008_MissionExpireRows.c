/* Age every row, compact rows[4] once a row reaches 600 ticks, and take the ov105 scene branch when
 * the compaction empties the list. 600 is the expiry threshold in ticks; the row stride is the
 * MissionRecord 0xc0 established by the first hand-off. */

#include "nitro/types.h"

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

extern MissionGlobals data_ov008_02090f24;
extern u8 data_ov008_0208fc84[];
extern int Game_PollSceneAlive(void);
extern void Ov105_SetParamWord8(u32 value);
extern void Ov105_WH_StartScan(void (*callback)(const MissionRecord *),
                                void *data, int value);
extern void VBlank_GetCount(void);
extern void Ov008_MissionUpsertRowByKey(const MissionRecord *record);
extern void Ov008_MissionDriveSound(void);

void *Ov008_MissionExpireRows(void) {
    switch (Game_PollSceneAlive()) {
    case 1:
        Ov105_SetParamWord8(0x800356);
        Ov105_WH_StartScan(Ov008_MissionUpsertRowByKey,
                            data_ov008_0208fc84, 0);
        break;

    case 2: {
        u8 i;

        VBlank_GetCount();
        for (i = 0; i < data_ov008_02090f24.context->row_count; i++) {
            u8 j;

            if (data_ov008_02090f24.context->row_states[i] < 600) {
                data_ov008_02090f24.context->row_states[i]++;
            }

            if (data_ov008_02090f24.context->row_states[i] >= 600) {
                for (j = i;
                     j < data_ov008_02090f24.context->row_count - 1;
                     j++) {
                    data_ov008_02090f24.context->rows[j] =
                        data_ov008_02090f24.context->rows[j + 1];
                }
                data_ov008_02090f24.context->row_count--;
                i--;
            }
        }
        break;
    }

    case 3:
        break;

    default:
        Ov008_MissionDriveSound();
        break;
    }

    return 0;
}
