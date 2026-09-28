/* Returns the width of a text in the text object's font (with its spacing). */

extern int NNSi_G2dFontGetTextWidth();

int func_020303bc(int arg0, int arg1) {
    return NNSi_G2dFontGetTextWidth(*(int *)(arg0 + 0x20), *(int *)(arg0 + 0x24), arg1, arg0);
}
