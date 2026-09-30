/* ov253 .rodata pointer tables, 0x020d4940-0x020d4950.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

extern int gOv253Bone05Name;
extern int gOv253Bone03Name;
extern int gOv253Bone02Name;
extern int gOv253Bone01Name;

void *const data_ov253_020d4940[4] = {

    &gOv253Bone01Name,

    &gOv253Bone02Name,

    &gOv253Bone03Name,

    &gOv253Bone05Name,

};
