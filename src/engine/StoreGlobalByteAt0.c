/* Stores the byte into a global. */

extern int data_020425e8;

void StoreGlobalByteAt0(char arg0) {
    *(char *)&data_020425e8 = arg0;
}
