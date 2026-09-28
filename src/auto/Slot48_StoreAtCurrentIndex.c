/* Index the stride-0x48 array by the current-index field at +0x124, store the argument at +0x20 of
 * that entry, and return the entry. */

int *Slot48_StoreAtCurrentIndex(int *r0, int r1)
{
    int idx = r0[0x49];
    int *p = (int *)((char *)r0 + idx * 0x48);
    p[8] = r1;
    return p;
}
