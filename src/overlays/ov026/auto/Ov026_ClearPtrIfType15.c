int Ov026_ClearPtrIfType15(char *obj) {
    if (*(unsigned short *)(*(int *)obj + 2) != 0x15) {
        return 0;
    }
    *(int *)obj = 0;
    return 1;
}
