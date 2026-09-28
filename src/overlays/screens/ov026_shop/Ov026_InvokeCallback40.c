/* Calls the object's callback at +0x40 with the argument when one is installed. */

void Ov026_InvokeCallback40(char *obj, void *arg) {
    void (*fp)(void *) = *(void (**)(void *))(obj + 0x40);
    if (fp) {
        fp(arg);
    }
}
