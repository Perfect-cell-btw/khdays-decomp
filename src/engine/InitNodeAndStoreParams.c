extern void Record_Init();
extern char data_02042928[];

int InitNodeAndStoreParams(int this_, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    Record_Init(this_, arg1, arg2, arg3);
    *(unsigned char *)(this_ + 0x21) = 3;
    *(char **)(this_ + 0x1c) = data_02042928;
    *(int *)(this_ + 0x38) = arg3;
    *(int *)(this_ + 0x3c) = arg4;
    *(int *)(this_ + 0x40) = arg5;
    *(int *)(this_ + 0x44) = arg6;
    return 1;
}
