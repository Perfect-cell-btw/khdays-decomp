/* ov025 .data tables, 0x020b4bb4-0x020b4c24.
 *
 * 1 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 *
 * Readers:
 *   data_ov025_020b4bb4: Ov025_Menu_ApplyFlagPresets
 */

#include "nitro/types.h"

int data_ov025_020b4bb4[28] = {
    7, 3, 8, 1, 9, 1, 10, 1,
    11, 3, 13, 1, 14, 3, 16, 1,
    17, 3, 18, 1, 19, 1, 111, 2,
    114, 2, 117, 2,
};
