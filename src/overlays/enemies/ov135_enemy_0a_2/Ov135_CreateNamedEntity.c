extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern int Ov107_OpenCachedResourceByName(char *buf);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov135_020d1c20[];
extern void Ov135_Construct(int);

int Ov135_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x3a8);
    *(signed char *)(obj + 0x19c) = 10;
    OS_SPrintf(buf, data_ov135_020d1c20, 10);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)Ov135_Construct;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
