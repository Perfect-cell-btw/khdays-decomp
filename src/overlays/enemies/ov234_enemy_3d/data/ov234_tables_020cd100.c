/* ov234 .rodata tables, 0x020cd100-0x020cd108.
 *
 * 2 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

/* read by Ov234_InitEffectActor (020cbfc4): const struct Ov234TextureTable data_ov234_020cd100; */

#include "nitro/types.h"

const int data_ov234_020cd100[1] = {
    1,
};

/* read by Ov234_ResolveHitReaction (020cc574): const struct Ov234ReactionModes data_ov234_020cd104; */
const u8 data_ov234_020cd104[4] = {
    0, 1, 2, 3,
};
