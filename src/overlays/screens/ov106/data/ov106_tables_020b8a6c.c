/* ov106 .rodata tables, 0x020b8a6c-0x020b8a84.
 *
 * 2 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

#include "nitro/types.h"

/* read by Ov106_LayoutMarkerWidget (not yet decompiled) */
const u8 data_ov106_020b8a6c[12] = {
    0, 192, 254, 255, 0, 96, 255, 255, 0, 0, 0, 0,
};

/* read by Ov106_ResetMarkerWidget (not yet decompiled) */
const u8 data_ov106_020b8a78[12] = {
    0, 192, 254, 255, 0, 0, 0, 0, 0, 0, 0, 0,
};
