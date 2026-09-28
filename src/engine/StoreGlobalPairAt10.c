/* Stores a pair of words into a global object. */

extern int data_0204bda4;

void StoreGlobalPairAt10(int arg0, int arg1) {
    *(int *)((char *)&data_0204bda4 + 0x10) = arg0;
    *(int *)((char *)&data_0204bda4 + 0x14) = arg1;
}
