/* Returns the address of the block at +0xd0 of the indexed entity record (0x184 bytes each) of the
 * entity manager. */

extern int data_0204c208;

int ArrayEntryPtrD0(int index) {
    return *(int *)&data_0204c208 + 0xd0 + index * 0x184;
}
