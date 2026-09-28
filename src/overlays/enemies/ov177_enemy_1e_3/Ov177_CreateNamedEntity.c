extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern int Ov107_OpenCachedResourceByName(char *buf);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov177_020d6320[];
extern void Ov177_Construct(int);

int Ov177_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x3b0);
    *(signed char *)(obj + 0x19c) = 30;
    OS_SPrintf(buf, data_ov177_020d6320, 30);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)Ov177_Construct;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
