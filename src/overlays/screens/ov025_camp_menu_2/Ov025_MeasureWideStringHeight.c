/* Height of a UTF-16 string in half-line units: 0 for an empty string, else two per line. */

int Ov025_MeasureWideStringHeight(unsigned short *str) {
    int count;
    unsigned short c;
    if (str == 0 || (c = *str) == 0) return 0;
    count = 2;
    while (c != 0) {
        if (c == 0xa) count += 2;
        c = *++str;
    }
    return count;
}
