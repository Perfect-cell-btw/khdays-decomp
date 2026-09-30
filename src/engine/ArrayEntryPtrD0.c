/* Returns the address of the block at +0xd0 of the indexed entity record (0x184 bytes each) of the
 * entity manager. */

extern int gEntityMgr;

int ArrayEntryPtrD0(int index) {
    return *(int *)&gEntityMgr + 0xd0 + index * 0x184;
}
