/* Returns the address of an entry of a six-entry table, or NULL out of range. */

extern int data_ov025_020b4ee8;

int Ov025_GetPageTableEntry(int arg0) {
    if ((unsigned int)arg0 >= 3) {
        return 0;
    }
    return (int)&data_ov025_020b4ee8 + arg0 * 0x12;
}
