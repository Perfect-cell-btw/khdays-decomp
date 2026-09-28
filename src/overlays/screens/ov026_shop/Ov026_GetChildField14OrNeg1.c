/* Returns the child's word at +0x14, or -1 without an object. */

int Ov026_GetChildField14OrNeg1(char *obj) {
    if (obj != 0) {
        return *(int *)(*(char **)(obj + 0xc) + 0x14);
    }
    return -1;
}
