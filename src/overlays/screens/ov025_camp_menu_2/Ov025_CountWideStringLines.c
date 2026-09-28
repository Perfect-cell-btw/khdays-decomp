/* Counts the lines of a UTF-16 string (newlines plus one). */

int Ov025_CountWideStringLines(unsigned short *str) {
    int count = 1;
    unsigned short c = *str;
    if (c != 0) {
        do {
            if (c == 0xa) count++;
            c = *++str;
        } while (c != 0);
    }
    return count;
}
