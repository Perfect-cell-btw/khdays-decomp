/* ov185 .rodata tables, 0x020d1690-0x020d16bc.
 *
 * 3 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

/* read by Ov185_Actor_Construct (020cdde8): const struct CameraWork data_ov185_020d1690; */

#include "nitro/types.h"

const int data_ov185_020d1690[4] = {
    0, 0, 0, 3072,
};

/* read by Ov185_HopArc_Step (020d0d5c): Pair data_ov185_020d16a0[];
 *   Publish the landing: copy the pending anchor into the live slot and ask the placement help (020d0efc): Ev data_ov185_020d16a0[];
 *   Ov185_Orbit_Step (020d11f4): Pair16 data_ov185_020d16a0[]; */
const u8 data_ov185_020d16a0[12] = {
    0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 5, 0,
};

/* read by Ov185_Actor_Construct_2 (020cfa2c): const struct CameraWork data_ov185_020d16ac; */
const int data_ov185_020d16ac[4] = {
    0, 0, 0, 2560,
};
