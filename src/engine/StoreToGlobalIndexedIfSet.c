/* Stores a word (+0xc) of the indexed entry (0x14 bytes each) of the entity manager's table at
 * +0x61c4, when that table exists. */

extern int data_0204c208;

void StoreToGlobalIndexedIfSet(int index, int *arg1) {
    int base = *(int *)(*(int *)&data_0204c208 + 0x61c4);
    if (base == 0) return;
    *(int *)(index * 0x14 + base + 0xc) = *arg1;
}
