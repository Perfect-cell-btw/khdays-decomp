/* Construct a named object: allocate 0x4ec bytes, format a debug name via OS_SPrintf,
 * register it (+0x1a4), install the 020cbfc8 callback (+0x18c) and init. Return it. */
extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern int Ov107_OpenCachedResourceByName(char *buf);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov256_020d2680[];
extern void Ov256_EnemyConstruct(int);
int Ov256_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x4ec);
    *(signed char *)(obj + 0x19c) = 0x50;
    OS_SPrintf(buf, data_ov256_020d2680, 80);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)&Ov256_EnemyConstruct;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
