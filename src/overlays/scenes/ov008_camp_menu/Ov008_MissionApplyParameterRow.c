/* Starts the parameter tweens for the selected mission row: four value tweens and three channel
 * tweens from the row's table, then marks the parameters ready. */

#include "nitro/types.h"

typedef struct {
    u8 values[9];
} MissionParameterRow;

typedef struct {
    u8 pad_000[0x24];
    u32 parameters_ready;
} MissionParameterContext;

extern u8 data_ov008_0208fc9c[];
extern u8 data_ov008_0208fc9d[];
extern u8 data_ov008_0208fc9e[];
extern u8 data_ov008_0208fc9f[];
extern u8 data_ov008_0208fca0[];
extern u8 data_ov008_0208fca3[];
extern u8 data_ov008_0208fca4[];
extern MissionParameterContext *data_ov008_02090fa0;

extern void Ov008_MissionStartTween(int value, int channel, int duration);
extern void Ov008_StartChannelTween(int value, int channel, int duration);

void Ov008_MissionApplyParameterRow(int row_index) {
    u32 offset = row_index * sizeof(MissionParameterRow);

    Ov008_MissionStartTween(data_ov008_0208fca0[offset], 0, 0x12c);
    Ov008_MissionStartTween(data_ov008_0208fc9c[offset], 1, 0x12c);
    Ov008_MissionStartTween(data_ov008_0208fc9e[offset], 2, 0x12c);
    Ov008_MissionStartTween(data_ov008_0208fc9d[offset], 3, 0x12c);
    Ov008_StartChannelTween(data_ov008_0208fca3[offset], 0, 0x12c);
    Ov008_StartChannelTween(data_ov008_0208fc9f[offset], 1, 0x12c);
    Ov008_StartChannelTween(data_ov008_0208fca4[offset], 2, 0x12c);
    data_ov008_02090fa0->parameters_ready = 1;
}
