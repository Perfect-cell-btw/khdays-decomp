void Ov262_RequestAction3WithParams(char *obj, int arg2, char arg3) {
    *(int *)(obj + 0x3a8) = arg2;
    obj[0x3ac] = arg3;
    obj[0x1c9] = 3;
    obj[0x1c7] = 3;
    *(int *)(obj + 0x3a4) = 1;
}
