/* Value of entry index of the second menu value table. */

extern int data_ov025_020b39e6;

int Ov025_GetTableValueB(int arg0) {
    return *(unsigned short *)((char *)&data_ov025_020b39e6 + arg0 * 8);
}
