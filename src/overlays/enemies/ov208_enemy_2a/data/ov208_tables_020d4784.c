/* ov208 .rodata tables, 0x020d4784-0x020d47d4.
 *
 * 2 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

/* read by Ov208_EnemyConstruct (not yet decompiled) */

#include "nitro/types.h"

const int data_ov208_020d4784[5] = {
    0, 20, 21, 22, 23,
};

/* read by * Ov208_MessageMapTableForward -- x3. Message handler: map the message kind through a 15-entry tabl (020d0694): struct t15 data_ov208_020d4798; */
const int data_ov208_020d4798[15] = {
    1, 2, 3, 4, 5, 6, 7, 8,
    9, 10, 11, 12, 13, 14, 15,
};
