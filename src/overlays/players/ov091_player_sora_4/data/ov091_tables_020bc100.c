/* ov091 .rodata tables, 0x020bc100-0x020bc118.
 *
 * 2 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

/* read by Ov091_Weapon_FireStraightShot (020bb490): Vec3 data_ov091_020bc100; */

#include "nitro/types.h"

const u8 data_ov091_020bc100[12] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0,
};

/* read by Ov091_Weapon_FireSpreadShot (020bb2e4): Vec3 data_ov091_020bc10c; */
const u8 data_ov091_020bc10c[12] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0,
};
