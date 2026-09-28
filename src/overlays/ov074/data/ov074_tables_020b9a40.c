/* ov074 .rodata tables, 0x020b9a40-0x020b9a58.
 *
 * 2 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

typedef unsigned char u8;
typedef unsigned short u16;

/* read by Ov074_Weapon_FireStraightShot (020b8dd0): Vec3 data_ov074_020b9a40; */
const u8 data_ov074_020b9a40[12] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0,
};

/* read by Ov074_Weapon_FireSpreadShot (020b8c24): Vec3 data_ov074_020b9a4c; */
const u8 data_ov074_020b9a4c[12] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0,
};
