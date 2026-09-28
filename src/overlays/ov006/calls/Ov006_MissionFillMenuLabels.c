typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 field_00[0x50];
    u16 label_text[0x38];
} MissionRecord;

typedef struct {
    u8 pad_000[0x100];
    u8 row_count;
    u8 pad_101[3];
    MissionRecord rows[4];
} MissionContext;

typedef u16 MissionLabel[11];

extern MissionContext *volatile data_ov006_020565e4;
extern u16 data_ov006_020563d4[];
extern void StrCopy16(u16 *dst, const u16 *src);

void Ov006_MissionFillMenuLabels(MissionLabel labels[4]) {
    int i;
    u8 row_count = data_ov006_020565e4->row_count;

    for (i = 0; i < 4; i++) {
        if (i < row_count) {
            StrCopy16(labels[i],
                          data_ov006_020565e4->rows[i].label_text);
        } else {
            StrCopy16(labels[i], data_ov006_020563d4);
        }
    }
}
