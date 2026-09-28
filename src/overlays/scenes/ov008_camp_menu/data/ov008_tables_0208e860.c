/* ov008 .rodata tables, 0x0208e860-0x0208e87c.
 *
 * 1 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 *
 * Readers:
 *   data_ov008_0208e860: Ov008_FlushDirtyCells
 */

#include "nitro/types.h"

const int data_ov008_0208e860[7] = {
    9, 10, 11, 24, 25, 26, 27,
};
