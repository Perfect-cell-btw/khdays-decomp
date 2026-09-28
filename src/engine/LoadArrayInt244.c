/* Returns a word (+0x244) of the indexed entity record (0x184 bytes each) of the entity manager. */

extern int data_0204c208;

int LoadArrayInt244(int index) {
    return *(int *)(*(int *)&data_0204c208 + index * 0x184 + 0x244);
}
