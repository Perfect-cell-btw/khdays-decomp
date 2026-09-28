/* ov053 .rodata tables, 0x020b7d70-0x020b7d7c.
 *
 * 1 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

#include "nitro/types.h"

/* read by Ov053_ReleaseIndexedHandles (020b6404): Idx3 data_ov053_020b7d70; */
const int data_ov053_020b7d70[3] = {
    0, 1, 2,
};
