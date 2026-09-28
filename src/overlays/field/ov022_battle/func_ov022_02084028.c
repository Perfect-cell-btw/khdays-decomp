/* Returns the battle context's scale as an integer, or 0 without a context. */

extern int *data_ov022_020b2e60;
int func_ov022_02084028(void) {
    int *p = data_ov022_020b2e60;
    if (p == 0) return 0;
    return p[7] >> 0xc;
}
