/* Construct a named object: allocate 0x49c bytes, format a debug name via OS_SPrintf,
 * register it (+0x1a4), install the 020cbfc8 callback (+0x18c) and init. Return it. */
extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern int Ov107_OpenCachedResourceByName(char *buf);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov277_020d3760[];
extern void Ov277_Construct(int);
int Ov277_CreateNamedEntity_2(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x49c);
    *(signed char *)(obj + 0x19c) = 0x62;
    OS_SPrintf(buf, data_ov277_020d3760, 98);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)&Ov277_Construct;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
