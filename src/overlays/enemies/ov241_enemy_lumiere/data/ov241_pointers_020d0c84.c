/* ov241 .rodata pointer tables, 0x020d0c84-0x020d0c90.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

extern int gOv241Tag02Name;
extern int gOv241Tag01Name;
extern int gOv241Tag00Name;

void *const data_ov241_020d0c84[3] = {

    &gOv241Tag00Name,

    &gOv241Tag01Name,

    &gOv241Tag02Name,

};
