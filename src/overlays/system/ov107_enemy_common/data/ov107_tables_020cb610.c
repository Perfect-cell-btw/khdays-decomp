/* ov107 .rodata tables, 0x020cb610-0x020cb628.
 *
 * 1 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

#include "nitro/types.h"

/* read by Ov107_LoadEnemyOverlay (020c0680): int data_ov107_020cb610[6]; */
const int data_ov107_020cb610[6] = {
    108, 109, 110, 111, 112, 113,
};
