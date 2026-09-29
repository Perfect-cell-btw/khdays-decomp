/* Returns a tagged script value as fx32: an integer (tag 1) is converted, tag 2 gives 0, anything
 * else is returned as it is. */

int Script_ValueToFx32(short *value) {
    int r = 0;
    if (*value == 1) r = *(int *)(value + 2) << 0xc;
    else if (*value != 2) r = *(int *)(value + 2);
    return r;
}
