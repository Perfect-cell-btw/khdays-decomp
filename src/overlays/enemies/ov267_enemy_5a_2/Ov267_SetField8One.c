/* Sets the word at +8 to 1. */

void Ov267_SetField8One(char *obj) {
    *(int *)(obj + 8) = 1;
}
