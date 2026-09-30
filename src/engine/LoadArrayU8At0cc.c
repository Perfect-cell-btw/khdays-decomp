/* Returns a byte of the indexed entity record (0x184 bytes each) of the entity manager. */

extern int gEntityMgr;

int LoadArrayU8At0cc(int index) {
    return *(unsigned char *)(*(int *)&gEntityMgr + index * 0x184 + 0xcc);
}
