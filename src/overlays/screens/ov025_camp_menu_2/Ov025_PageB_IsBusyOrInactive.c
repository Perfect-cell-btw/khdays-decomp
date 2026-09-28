/* Look up the object for param_1; return 0 only when its bit 2 flag at +0x28 is
 * set and the word at +0x1f0 is zero; otherwise 1. */
extern int Ov025_GetPageB(int arg);

struct flags_0207890c { unsigned int pad : 2; unsigned int active : 1; };

int Ov025_PageB_IsBusyOrInactive(int param_1) {
    int obj = Ov025_GetPageB(param_1);
    return !((struct flags_0207890c *)(obj + 0x28))->active
        || *(int *)(obj + 0x1f0) != 0;
}
