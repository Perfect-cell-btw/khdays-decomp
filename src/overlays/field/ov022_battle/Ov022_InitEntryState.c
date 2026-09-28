/* Zeroes the entry header (halfword at obj[0], bytes at obj+2, words at obj+8/0x54), sets the two
 * ids at obj+0xC/0x10 to -1, clears the 15-word array at obj+0x18, and writes 0xFFFF to the
 * halfword at obj+0x6c. */

void Ov022_InitEntryState(char *obj) {
    int i;
    int *q;
    *(short *)obj = 0;
    *(int *)(obj + 8) = 0;
    obj[2] = 0;
    *(int *)(obj + 0x54) = 0;
    *(int *)(obj + 0xc) = -1;
    *(int *)(obj + 0x10) = -1;
    q = (int *)obj;
    for (i = 0; i < 15; i++) { q[6] = 0; q++; }
    *(unsigned short *)(obj + 0x6c) = 0xffff;
}
