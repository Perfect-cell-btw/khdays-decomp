/* Calls the element's velocity hook (vtable +0x34); returns 0 when it has none. */

int Ov002_GetElementVelocity(int arg0) {
    int (*f)(int) = *(int (**)(int))(*(int *)(arg0 + 8) + 0x34);
    if (f == 0) {
        return 0;
    }
    return f(arg0);
}
