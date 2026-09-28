/* ov105 .data tables, 0x020bfa00-0x020bfa20.
 *
 * 1 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

#include "nitro/types.h"

unsigned int data_ov105_020bfa00[8] = {
    0x10000, 0, 0, 0, 0, 0, 0, 0,
};
