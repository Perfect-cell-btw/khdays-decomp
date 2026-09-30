/* Hit reaction: for hit flags with bits 0 and 4 set, sets the knockback distance (0x16000) and
 * reports the hit as not absorbed (returns 0); returns 1 otherwise. */

int Ov263_SetField1cIfFlags1And10(char *obj, int unused, int *flags) {
    char *base = *(char **)(obj + 0x214);
    unsigned v = (unsigned short)*flags;
    if ((v & 1) && (v & 0x10)) {
        *(int *)(base + 0x1c) = 0x16000;
        return 0;
    }
    return 1;
}
