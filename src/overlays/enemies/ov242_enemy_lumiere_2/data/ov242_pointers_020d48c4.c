/* ov242 .rodata pointer tables, 0x020d48c4-0x020d48d0.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

extern int gOv242Tag02Name;
extern int gOv242Tag01Name;
extern int gOv242Tag00Name;

void *const data_ov242_020d48c4[3] = {

    &gOv242Tag00Name,

    &gOv242Tag01Name,

    &gOv242Tag02Name,

};
