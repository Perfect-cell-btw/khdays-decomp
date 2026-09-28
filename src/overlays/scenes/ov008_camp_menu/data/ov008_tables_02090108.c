/* ov008 .data tables, 0x02090108-0x02090148.
 *
 * 1 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 *
 * Readers:
 *   data_ov008_02090108: Ov008_Menu_ApplyFlagPresets
 */

#include "nitro/types.h"

int data_ov008_02090108[16] = {
    7, 8, 8, 8, 9, 8, 10, 8,
    11, 8, 12, 8, 13, 8, 14, 8,
};
