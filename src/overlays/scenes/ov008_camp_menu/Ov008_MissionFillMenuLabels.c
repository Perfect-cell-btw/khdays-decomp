#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
typedef u16 MissionLabel[11];

#define MISSION_CONTEXT (*(MissionContext * volatile *)&data_ov008_02090f24.pContext)
extern u16 data_ov008_02090bc4[];
extern void StrCopy16(u16 *dst, const u16 *src);

void Ov008_MissionFillMenuLabels(MissionLabel labels[4]) {
    int i;
    u8 row_count = MISSION_CONTEXT->rowCount;

    for (i = 0; i < 4; i++) {
        if (i < row_count) {
            StrCopy16(labels[i], MISSION_CONTEXT->rows[i].labelText);
        } else {
            StrCopy16(labels[i], data_ov008_02090bc4);
        }
    }
}
