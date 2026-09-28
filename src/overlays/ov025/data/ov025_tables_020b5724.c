/* ov025 .data tables, 0x020b5724-0x020b5740.
 *
 * 1 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 *
 * Readers:
 *   data_ov025_020b5724: Ov025_ReportDetail_DrawLines, Ov025_ReportDetail_Refresh
 */

typedef unsigned char u8;
typedef unsigned short u16;

u8 data_ov025_020b5724[28] = {
    63, 0, 63, 0, 63, 0, 63, 0, 63, 0, 63, 0, 63, 0, 63, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
