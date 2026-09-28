void Ov002_InvokeCallback40(char *obj, void *arg) {
    void (*fp)(void *) = *(void (**)(void *))(obj + 0x40);
    if (fp) {
        fp(arg);
    }
}
