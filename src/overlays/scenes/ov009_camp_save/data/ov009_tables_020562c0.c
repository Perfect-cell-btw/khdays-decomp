/* ov009 .data tables, 0x020562c0-0x020562dc.
 *
 * 2 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

/* The menu archive path ("UI/cm/cmo_&.p2", '&' = language code) followed by an end marker. */

#include "nitro/types.h"

struct {
    char path[16];
    int end;
} data_ov009_020562c0 = { "UI/cm/cmo_&.p2", -1 };

int data_ov009_020562d4[2] = {
    0, -1,
};
