/* Stores a word (+0x244) of the indexed entity record (0x184 bytes each) of the entity manager. */

extern int gEntityMgr;

void StoreArrayInt244(int index, int value) {
    *(int *)(*(int *)&gEntityMgr + index * 0x184 + 0x244) = value;
}
