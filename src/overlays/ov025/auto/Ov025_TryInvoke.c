int Ov025_TryInvoke(void *fp, void *arg) {
    int r = 0;
    if (fp) {
        ((void (*)(void *))fp)(arg);
        r = 1;
    }
    return r;
}
