/* Value of entry index of the menu value table. */

extern int data_ov025_020b39e4;

int Ov025_GetTableValue(int arg0) {
    return *(unsigned short *)((char *)&data_ov025_020b39e4 + arg0 * 8);
}
