/* ov025 .data tables, 0x020b535c-0x020b536c.
 *
 * 1 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 *
 * Readers:
 *   data_ov025_020b535c: Ov025_DrawMissionRow
 */

#include "nitro/types.h"

u8 data_ov025_020b535c[16] = {
    37, 0, 48, 0, 50, 0, 100, 0, 37, 0, 99, 0, 0, 0, 0, 0,
};
