/* Child task teardown: marks the child's manager dirty (bit 1 of +0x5c) and clears the word its
 * entry (+0x3dc) holds at +4. */

void Ov202_ChildTaskTeardown(char *obj) {
    char *p = *(char **)(obj + 4);
    *(int *)(*(char **)(p + 0x4) + 0x5c) |= 2;
    *(int *)(*(char **)(*(char **)(p + 0x0) + 0x3dc) + 0x4) = 0;
}
