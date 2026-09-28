/* Returns a tagged value as fx32: an integer (tag 1) is converted, tag 2 gives 0, anything else is
 * returned as it is. */

int func_020219c4(short *arg0) {
    int r = 0;
    if (*arg0 == 1) r = *(int *)(arg0 + 2) << 0xc;
    else if (*arg0 != 2) r = *(int *)(arg0 + 2);
    return r;
}
