/* Returns a word of the object the object's +8 points to. */

int Ov015_GetField8Field78_2(char *obj) {
    return *(int *)(*(char **)(obj + 8) + 0x78);
}
