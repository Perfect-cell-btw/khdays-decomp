/* Creates enemy 18's actor: opens its cached resource by name and initialises it. */

extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern int Ov107_OpenCachedResourceByName(char *buf);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov149_020d07a0[];
extern void Ov149_Ov149ActorInit(int);

int Ov149_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x3d4);
    *(signed char *)(obj + 0x19c) = 18;
    OS_SPrintf(buf, data_ov149_020d07a0, 18);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)Ov149_Ov149ActorInit;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
