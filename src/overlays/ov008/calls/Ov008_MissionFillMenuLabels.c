typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 text[0x60];
} MissionMenuRow;

typedef struct {
    u8 pad_000[0x100];
    u8 row_count;
    u8 pad_101[0x53];
    MissionMenuRow rows[4];
} MissionContext;

typedef u16 MissionLabel[11];

extern MissionContext *volatile data_ov008_02090f24;
extern u16 data_ov008_02090bc4[];
extern void StrCopy16(u16 *dst, const u16 *src);

void Ov008_MissionFillMenuLabels(MissionLabel labels[4]) {
    int i;
    u8 row_count = data_ov008_02090f24->row_count;

    for (i = 0; i < 4; i++) {
        if (i < row_count) {
            StrCopy16(labels[i], data_ov008_02090f24->rows[i].text);
        } else {
            StrCopy16(labels[i], data_ov008_02090bc4);
        }
    }
}
