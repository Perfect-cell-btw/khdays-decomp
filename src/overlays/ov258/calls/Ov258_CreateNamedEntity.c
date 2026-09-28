/* Construct a named object: allocate 0x5bc bytes, format a debug name via OS_SPrintf,
 * register it (+0x1a4), install the 020cbfc8 callback (+0x18c) and init. Return it. */
extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern int Ov107_OpenCachedResourceByName(char *buf);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov258_020d1860[];
extern void Ov258_Construct(int);
int Ov258_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x5bc);
    *(signed char *)(obj + 0x19c) = 0x52;
    OS_SPrintf(buf, data_ov258_020d1860, 82);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)&Ov258_Construct;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
