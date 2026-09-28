/* Returns the record with the given index from a list of length-prefixed variable-size records
 * (count at +4, first record at +8), or NULL when the index is out of range. */

void *Ov025_GetVarRecordByIndex(int *s, int idx) {
    unsigned int count = s[1];
    char *p = (char *)s[2];
    int i;
    if ((unsigned int)idx >= count) {
        return 0;
    }
    for (i = 0; i < idx; i++) {
        p += *(int *)p;
    }
    return p + 4;
}
