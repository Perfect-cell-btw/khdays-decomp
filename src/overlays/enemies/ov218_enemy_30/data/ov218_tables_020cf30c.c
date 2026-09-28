/* ov218 .rodata tables, 0x020cf30c-0x020cf318.
 *
 * 3 contiguous tables, each written in the width its contents are in:
 * words where the values are small integers, bytes where the words are
 * packed bytes.
 */

typedef unsigned char u8;
typedef unsigned short u16;

/* read by Ov218_Construct (not yet decompiled) */
const int data_ov218_020cf30c[1] = {
    1026,
};

/* read by Ov218_OnDamage (not yet decompiled) */
const u8 data_ov218_020cf310[4] = {
    0, 1, 2, 3,
};

/* read by Ov218_Build (not yet decompiled) */
const int data_ov218_020cf314[1] = {
    1541,
};
