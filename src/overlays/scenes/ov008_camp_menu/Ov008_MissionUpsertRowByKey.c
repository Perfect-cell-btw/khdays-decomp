#include "nitro/types.h"

#include "game/ov008_camp_menu.h"

/* Inserts or updates a mission row by its six-byte key: an existing row is overwritten, otherwise
 * the record is appended while there is room (four rows). */

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

void Ov008_MissionUpsertRowByKey(const MissionRecord *record) {
    MissionContext *context = MISSION_CONTEXT;
    int initial_count = context->rowCount;
    int found = 0;
    int i = 0;

    if (initial_count > 0) {
        u8 *key = context->rows[0].key;

        do {
            if (key[0] == record->key[0] &&
                key[1] == record->key[1] &&
                key[2] == record->key[2] &&
                key[3] == record->key[3] &&
                key[4] == record->key[4] &&
                key[5] == record->key[5]) {
                MI_CpuCopy8(record, &context->rows[i],
                            sizeof(MissionRecord));
                MISSION_CONTEXT->rowStates[i] = 0;
                found = 1;
                break;
            }
            i++;
            key += sizeof(MissionRecord);
        } while (i < context->rowCount);
    }

    if (found != 0) {
        return;
    }
    if (MISSION_CONTEXT->rowCount >= 4) {
        return;
    }

    MI_CpuCopy8(record, &MISSION_CONTEXT->rows[i],
                sizeof(MissionRecord));
    MISSION_CONTEXT->rowStates[i] = 0;
    MISSION_CONTEXT->rowCount++;
}
