/* ov186 .rodata tables, 0x020d34b0-0x020d34dc.
 *
 * 3 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

/* read by Ov186_Actor_Construct (020cfc08): const struct CameraWork data_ov186_020d34b0; */

#include "nitro/types.h"

const int data_ov186_020d34b0[4] = {
    0, 0, 0, 3072,
};

/* read by Ov186_OrbitStep (020d2b7c): Pair data_ov186_020d34c0[];
 *   Publish the landing: copy the pending anchor into the live slot and ask the placement help (020d2d1c): Ev data_ov186_020d34c0[];
 *   Ov186_EmitAtOrbit (020d3014): Pair16 data_ov186_020d34c0[]; */
const u8 data_ov186_020d34c0[12] = {
    0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 5, 0,
};

/* read by Ov186_InitEffectActor (020d184c): const struct CameraWork data_ov186_020d34cc; */
const int data_ov186_020d34cc[4] = {
    0, 0, 0, 2560,
};
