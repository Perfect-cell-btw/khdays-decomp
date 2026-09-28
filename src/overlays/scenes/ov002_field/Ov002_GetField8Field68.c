/* Returns a word of the object the object's +8 points to. */

int Ov002_GetField8Field68(char *obj) {
    return *(int *)(*(char **)(obj + 8) + 0x68);
}
