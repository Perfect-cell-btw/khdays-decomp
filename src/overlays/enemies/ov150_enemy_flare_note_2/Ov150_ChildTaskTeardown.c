/* Child task teardown: flags the child (+0x5c bit 1) and clears the owner's back link. */

void Ov150_ChildTaskTeardown(char *obj) {
    char *p = *(char **)(obj + 4);
    *(int *)(*(char **)(p + 0x4) + 0x5c) |= 2;
    *(int *)(*(char **)(*(char **)(p + 0x0) + 0x390) + 0x4) = 0;
}
