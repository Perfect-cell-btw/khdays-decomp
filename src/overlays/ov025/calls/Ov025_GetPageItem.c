extern int Ov025_GetPageTableEntry();
extern int data_ov025_020b4ed0;

int Ov025_GetPageItem(int arg0, int arg1) {
    int base = Ov025_GetPageTableEntry(arg0);
    if (arg1 >= *(unsigned char *)(base + 2)) {
        return 0;
    }
    return (int)((char *)&data_ov025_020b4ed0 + *(unsigned char *)(base + arg1 + 3) * 4);
}
