/* Construct a named object: allocate 0x3f8 bytes, format a debug name via OS_SPrintf,
 * register it (+0x1a4), install the 020d3a08 callback (+0x18c) and init. Return it. */
extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern int Ov107_OpenCachedResourceByName(char *buf);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov197_020ce8c0[];
extern void Ov197_InitActor(int);
int Ov197_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x3f8);
    *(signed char *)(obj + 0x19c) = 37;
    OS_SPrintf(buf, data_ov197_020ce8c0, 37);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)&Ov197_InitActor;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
