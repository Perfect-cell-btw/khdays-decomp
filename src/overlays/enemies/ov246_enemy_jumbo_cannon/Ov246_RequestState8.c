/* Reaction check: unless the current action (+0x1c6) is 6 or 7, requests action 8 when no action is
 * pending; returns whether it did. */

int Ov246_RequestState8(char *obj) {
    char *base = *(char **)(*(char **)(obj + 0x214));
    int s = *(signed char *)(base + 0x1c6);
    /* goto forces cmp;cmpne over the range-opt (sub;cmp #1) for s==6||s==7 */
    if (s == 6 || s == 7) goto reject;
    if (0) {
    reject:
        return 0;
    }
    if (*(signed char *)(base + 0x1c7) == -1) {
        *(char *)(base + 0x1c7) = 8;
        return 1;
    }
    return 0;
}
