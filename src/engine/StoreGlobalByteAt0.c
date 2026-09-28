/* Stores the byte into a global. Returns the byte. */

extern int data_020425e8;

char StoreGlobalByteAt0(char arg0) {
    *(char *)&data_020425e8 = arg0;
    return arg0;
}
