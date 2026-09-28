int Ov002_Element_CallHook2C(int arg0) {
    int (*f)(int) = *(int (**)(int))(*(int *)(arg0 + 8) + 0x2c);
    if (f == 0) {
        return 0;
    }
    return f(arg0);
}
