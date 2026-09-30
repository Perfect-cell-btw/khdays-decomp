/* ov004 .rodata pointer tables, 0x020510a4-0x020510b0.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

extern int gOv004UiCmMslPath;

void *const data_ov004_020510a4[3] = {

    &gOv004UiCmMslPath,

    0,

    0,

};
