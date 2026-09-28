typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 values[9];
} MissionParameterRow;

typedef struct {
    u8 pad_000[0x24];
    u32 parameters_ready;
} MissionParameterContext;

extern u8 data_ov006_020561e0[];
extern u8 data_ov006_020561e1[];
extern u8 data_ov006_020561e2[];
extern u8 data_ov006_020561e3[];
extern u8 data_ov006_020561e4[];
extern u8 data_ov006_020561e7[];
extern u8 data_ov006_020561e8[];
extern MissionParameterContext *data_ov006_02056660;

extern void Ov006_MissionStartTween(int value, int channel, int duration);
extern void Ov006_StartChannelTween(int value, int channel, int duration);

void Ov006_MissionApplyParameterRow(int row_index) {
    u32 offset = row_index * sizeof(MissionParameterRow);

    Ov006_MissionStartTween(data_ov006_020561e4[offset], 0, 0x12c);
    Ov006_MissionStartTween(data_ov006_020561e0[offset], 1, 0x12c);
    Ov006_MissionStartTween(data_ov006_020561e2[offset], 2, 0x12c);
    Ov006_MissionStartTween(data_ov006_020561e1[offset], 3, 0x12c);
    Ov006_StartChannelTween(data_ov006_020561e7[offset], 0, 0x12c);
    Ov006_StartChannelTween(data_ov006_020561e3[offset], 1, 0x12c);
    Ov006_StartChannelTween(data_ov006_020561e8[offset], 2, 0x12c);
    data_ov006_02056660->parameters_ready = 1;
}
