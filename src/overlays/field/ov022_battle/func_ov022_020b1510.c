/* Whether the request is posted (bit 1) and not done (bit 2). */

int func_ov022_020b1510(unsigned char *arg0) {
    int r = 0;
    if ((*arg0 & 2) == 0) return r;
    if ((*arg0 & 4) == 0) r = 1;
    return r;
}
