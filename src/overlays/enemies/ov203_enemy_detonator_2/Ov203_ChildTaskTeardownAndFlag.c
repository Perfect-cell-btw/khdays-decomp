/* Child task teardown: flags the child, clears the owner's link (+0x3dc) and sets owner +0x3e0 bit
 * 0. */

void Ov203_ChildTaskTeardownAndFlag(char *p) {
    char *r3 = *(char **)(p + 4);
    char *r2 = *(char **)(r3 + 4);
    *(int *)(r2 + 0x5c) |= 2;
    *(int *)(*(char **)(*(char **)r3 + 0x3dc) + 0x24) = 0;
    {
        int *pf = (int *)(*(char **)r3 + 0x3e0);
        *pf = (*pf & ~1) | 1;
    }
}
