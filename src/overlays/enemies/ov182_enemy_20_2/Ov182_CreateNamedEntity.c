extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern int Ov107_OpenCachedResourceByName(char *buf);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov182_020d0860[];
extern void Ov182_Construct(int);

int Ov182_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x39c);
    *(signed char *)(obj + 0x19c) = 32;
    OS_SPrintf(buf, data_ov182_020d0860, 32);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)Ov182_Construct;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
