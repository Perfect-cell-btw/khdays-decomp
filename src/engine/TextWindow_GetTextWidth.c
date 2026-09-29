/* Returns the width of a text in the window's font (+0x20) with its horizontal spacing (+0x24). */

extern int NNSi_G2dFontGetTextWidth();

int TextWindow_GetTextWidth(int window, int text) {
    return NNSi_G2dFontGetTextWidth(*(int *)(window + 0x20), *(int *)(window + 0x24), text, window);
}
