/* ov243 .rodata pointer tables, 0x020d4748-0x020d4754.
 *
 * 1 table: the joint names the constructor (020d393c) resolves on the +0x384 item; only the
 * first entry is set. All zero in the ROM image because the entry is a relocation.
 */

extern char gOv243BoneHeadName[];

void *const data_ov243_020d4748[3] = {

    gOv243BoneHeadName,

    0,

    0,

};
