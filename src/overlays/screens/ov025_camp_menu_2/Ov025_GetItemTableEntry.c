/* Returns the address of an entry of a six-entry table, or NULL out of range. */

extern int data_ov025_020b4ed0;

int Ov025_GetItemTableEntry(int arg0) {
    if ((unsigned int)arg0 >= 6) {
        return 0;
    }
    return (int)&data_ov025_020b4ed0 + arg0 * 4;
}
