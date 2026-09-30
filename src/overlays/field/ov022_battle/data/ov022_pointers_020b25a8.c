/* ov022 .rodata pointer tables, 0x020b25a8-0x020b25b4.
 *
 * 1 table, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

extern int gOv022BaEfSBurnPackPath;
extern int gOv022BaEfSShockPackPath;
extern int gOv022BaEfSFrostPackPath;

void *const data_ov022_020b25a8[3] = {

    &gOv022BaEfSBurnPackPath,

    &gOv022BaEfSShockPackPath,

    &gOv022BaEfSFrostPackPath,

};
