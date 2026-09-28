/* Draw one 6 x 0x4d cell of the tall layout table in style 0 with flag 1. The
 * table rows are 6 bytes wide, so the ROM reaches the row with an mla rather
 * than a shift. */
extern void Ov002_BlitNibbleRun(int a, int b, int width, int height,
                                int flags, int style, void *row);

typedef struct {
    unsigned char bytes[6];
} Ov002TallRow;

extern Ov002TallRow data_ov002_0207ddb4[];

void Ov002_DrawTallLayoutRow(int a, int b, int row) {
    Ov002_BlitNibbleRun(a, b, 6, 0x4d, 1, 0, &data_ov002_0207ddb4[row]);
}
