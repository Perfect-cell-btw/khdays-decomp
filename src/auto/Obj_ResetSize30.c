/* Sets the object's first word to 0x30; returns 1. */

int Obj_ResetSize30(int *p) {
    *p = 0x30;
    return 1;
}
