/* ov266 .rodata tables, 0x020d3f20-0x020d3f48.
 *
 * 1 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

#include "nitro/types.h"

/* read by Ov266_Construct (020ce43c): IdTable data_ov266_020d3f20; */
const int data_ov266_020d3f20[10] = {
    0, 0, 3, 4, 5, 6, 9, 10,
    11, 12,
};
