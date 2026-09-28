/* ov025 .data tables, 0x020b52ec-0x020b52fc.
 *
 * 2 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 *
 * Readers:
 *   data_ov025_020b52ec: Ov025_BuildTable20AndDelegate
 *   data_ov025_020b52f8: Ov025_DrawStatusField
 */

#include "nitro/types.h"

u8 data_ov025_020b52ec[12] = {
    37, 0, 100, 0, 47, 0, 37, 0, 100, 0, 0, 0,
};

u8 data_ov025_020b52f8[4] = {
    252, 48, 0, 0,
};
