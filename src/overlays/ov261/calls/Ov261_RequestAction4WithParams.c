void Ov261_RequestAction4WithParams(char *obj, int arg2, char arg3) {
    *(int *)(obj + 0x3a8) = arg2;
    obj[0x3ac] = arg3;
    obj[0x1c9] = 4;
    obj[0x1c7] = 4;
    *(int *)(obj + 0x3a4) = 1;
}
