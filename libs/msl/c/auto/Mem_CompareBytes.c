/* memcmp: compare n bytes; 0 if equal, -1 if a<b, 1 if a>b. */
int Mem_CompareBytes(unsigned char *a, unsigned char *b, int n) {
    while (n != 0) {
        if (*a++ != *b++) {
            return (a[-1] < b[-1]) ? -1 : 1;
        }
        n--;
    }
    return 0;
}
