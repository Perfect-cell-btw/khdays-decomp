/* Number of lines (newline-separated) of a wide string. */

int Ov002_CountTextLines(unsigned short *p) {
    int count = 1;
    if (*p != 0) {
        do {
            if (*p == 0xa) {
                count++;
            }
            p++;
        } while (*p != 0);
    }
    return count;
}
