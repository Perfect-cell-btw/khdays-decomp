/* ov119 .rodata tables, 0x020cf93c-0x020cf960.
 *
 * 2 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

/* read by refresh sub-node #0's local transform, then publish it. (020cbfc4): struct blk4 data_ov119_020cf93c; */

#include "nitro/types.h"

const int data_ov119_020cf93c[4] = {
    0, 2896, 2896, 0,
};

/* read by Ov119_Construct (020cc02c): KindTable data_ov119_020cf94c; */
const int data_ov119_020cf94c[5] = {
    1, 2, 3, 4, 5,
};
