/* ov054 .rodata tables, 0x020b7360-0x020b7378.
 *
 * 2 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

#include "nitro/types.h"

/* read by Ov054_Weapon_FireStraightShot (020b66f0): Vec3 data_ov054_020b7360; */
const u8 data_ov054_020b7360[12] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0,
};

/* read by Ov054_Weapon_FireSpreadShot (020b6544): Vec3 data_ov054_020b736c; */
const u8 data_ov054_020b736c[12] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0,
};
