/* Stores an entry of the global slot array (data_0204c22c + 0xc). */

extern int data_0204c22c;

void StoreGlobalPtrArray4At0c(int index, int value) {
    int base = *(int *)&data_0204c22c;
    *(int *)(base + index * 4 + 0xc) = value;
}
