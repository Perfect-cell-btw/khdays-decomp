/* ov025 .data tables, 0x020b52c4-0x020b52d4.
 *
 * 2 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 *
 * Readers:
 *   data_ov025_020b52c4: Ov025_DrawListEntryRow, Ov025_BuildTable11AndDelegate
 *   data_ov025_020b52cc: Ov025_DrawListEntryRow, Ov025_BuildTableAndDelegate
 */

typedef unsigned char u8;
typedef unsigned short u16;

u8 data_ov025_020b52c4[8] = {
    37, 0, 43, 0, 100, 0, 0, 0,
};

u8 data_ov025_020b52cc[8] = {
    37, 0, 100, 0, 0, 0, 0, 0,
};
