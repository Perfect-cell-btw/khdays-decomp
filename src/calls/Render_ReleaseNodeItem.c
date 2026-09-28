extern void Render_ReleaseItemOnce(void *);

void Render_ReleaseNodeItem(unsigned char *param_1) {
    if ((param_1[8] & 4) == 0) {
        return;
    }
    Render_ReleaseItemOnce(param_1 + 0xc);
    param_1[8] &= ~4;
}
