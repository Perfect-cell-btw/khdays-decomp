/* ov090 .rodata tables, 0x020bcb10-0x020bcb1c.
 *
 * 1 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

#include "nitro/types.h"

/* read by Ov090_ReleaseIndexedHandles (020bb1a4): Idx3 data_ov090_020bcb10; */
const int data_ov090_020bcb10[3] = {
    0, 1, 2,
};
