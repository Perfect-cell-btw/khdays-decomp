/* UTF-16 string concatenation: appends `src` to `dst` and returns `dst`. */
unsigned short *STD_WStrCat(unsigned short *dst, const unsigned short *src) {
    unsigned short *p = dst;
    while (*p++ != 0) {
        ;
    }
    p--;
    while ((*p++ = *src++) != 0) {
        ;
    }
    return dst;
}
