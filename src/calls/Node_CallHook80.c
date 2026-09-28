typedef int (*fp)();

int Node_CallHook80(char *p) {
    fp f = *(fp *)(p + 0x80);
    if (f == 0)
        return;
    return f();
}
