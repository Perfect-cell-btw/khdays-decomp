/* ov025 .rodata pointer tables, 0x020b4220-0x020b4228.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

extern int gOv025RptName;
extern int gOv025EnmName;

void *const data_ov025_020b4220[2] = {

    &gOv025RptName,

    &gOv025EnmName,

};
