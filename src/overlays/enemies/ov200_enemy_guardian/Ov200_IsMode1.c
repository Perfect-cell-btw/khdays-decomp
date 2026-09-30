/* Tests a bit field of the word at +0x38. */

int Ov200_IsMode1(char *obj) {
    int x = *(int *)(obj + 0x38);
    x = (x << 28) >> 28;
    return x == 1;
}
