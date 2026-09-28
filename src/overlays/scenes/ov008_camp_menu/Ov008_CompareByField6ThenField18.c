/* Ordering predicate: compares two records by the halfword at +6, then by the word at +0x18. */

int Ov008_CompareByField6ThenField18(char *a, char *b) {
    unsigned short hb = *(unsigned short *)(b + 6);
    unsigned short ha = *(unsigned short *)(a + 6);
    if (ha > hb) return 1;
    if (ha < hb) return 0;
    return *(int *)(a + 0x18) > *(int *)(b + 0x18);
}
