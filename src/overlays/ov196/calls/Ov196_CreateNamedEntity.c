extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern int Ov107_OpenCachedResourceByName(char *buf);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov196_020d6860[];
extern void Ov196_Construct(int);

int Ov196_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x3d8);
    *(signed char *)(obj + 0x19c) = 36;
    OS_SPrintf(buf, data_ov196_020d6860, 36);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)Ov196_Construct;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
