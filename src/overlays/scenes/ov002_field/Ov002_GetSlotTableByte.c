/* Return the signed byte at index `i` of the 4-byte table at +0x2f of the ov002 context, or -1 for
 * a negative index. Ov002_ReleaseContextBuffers fills that table with 0xff, which is what
 * identifies 0xff as its empty-slot marker. */

extern int data_ov002_0207fa10;

int Ov002_GetSlotTableByte(int arg0) {
    if (arg0 >= 0) {
        return *(signed char *)(*(int *)&data_ov002_0207fa10 + arg0 + 0x2f);
    }
    return -1;
}
