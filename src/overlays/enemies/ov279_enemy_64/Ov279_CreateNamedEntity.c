/* Construct a named object: allocate 0x3b4 bytes, format a debug name via OS_SPrintf,
 * register it (+0x1a4), install the 020cfc6c callback (+0x18c) and init. Return it. */
extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern int Ov107_OpenCachedResourceByName(char *buf);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov279_020d35c0[];
extern void Ov279_Construct(int);
int Ov279_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x3b4);
    *(signed char *)(obj + 0x19c) = 100;
    OS_SPrintf(buf, data_ov279_020d35c0, 100);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)&Ov279_Construct;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
