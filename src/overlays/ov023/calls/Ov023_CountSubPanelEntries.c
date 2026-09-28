#pragma thumb on
/* Ov023_CountSubPanelEntries -- count the leading non-empty sub-panel entries (max 5),
 * ov023. Entries are 0xc bytes apart starting at obj+0x464. */
int Ov023_CountSubPanelEntries(char *obj) {
    int n = 0;
    for (;;) {
        if (*(int *)(obj + 0x464) == 0) {
            break;
        }
        n++;
        obj += 0xc;
        if (n >= 5) {
            break;
        }
    }
    return n;
}
