/* Sets the halfword at +0x20 to 1. */

void Ov025_SetHalfword20(char *obj) {
    *(short *)(obj + 0x20) = 1;
}
