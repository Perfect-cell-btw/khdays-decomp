/* Fill the menu labels from MissionContext.aRows[i].awLabelText, with data_ov006_020563d4 as the
 * fallback; bRowCount at +0x100 is the count. CORRECTED 2026-07-20: an earlier version of this
 * comment said the rows live at +0x154 with stride 0xc0, which never closed -- 0x154..0x414 is 704
 * bytes and not a multiple of 0xc0. The rows start at +0x104; the 0x154 that looked like an array
 * base is +0x104 + 0x50, the label field's offset INSIDE the record. The layout then closes
 * exactly: rows[4] fill 0x104..0x403, aRowStates[4] fill 0x404..0x413, and the selection block
 * follows at 0x414. */

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
