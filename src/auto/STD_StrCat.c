/* strcat: appends `src` to `dst` and returns `dst`. */
char *STD_StrCat(char *dst, const char *src) {
    char *p = dst;
    while (*p++ != 0) {
        ;
    }
    p--;
    while ((*p++ = *src++) != 0) {
        ;
    }
    return dst;
}
