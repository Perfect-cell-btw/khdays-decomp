/* ov025 .rodata tables, 0x020b37c4-0x020b37e0.
 *
 * 1 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 *
 * Readers:
 *   data_ov025_020b37c4: Ov025_FlushDirtyCells
 */

#include "nitro/types.h"

const int data_ov025_020b37c4[7] = {
    9, 10, 11, 24, 25, 26, 27,
};
