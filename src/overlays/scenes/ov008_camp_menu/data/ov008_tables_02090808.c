/* ov008 .data tables, 0x02090808-0x02090818.
 *
 * 2 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 *
 * Readers:
 *   data_ov008_02090808: Ov008_BuildTable20AndDelegate
 *   data_ov008_02090814: Ov008_DrawStatusField
 */

#include "nitro/types.h"

u8 data_ov008_02090808[12] = {
    37, 0, 100, 0, 47, 0, 37, 0, 100, 0, 0, 0,
};

u8 data_ov008_02090814[4] = {
    252, 48, 0, 0,
};
