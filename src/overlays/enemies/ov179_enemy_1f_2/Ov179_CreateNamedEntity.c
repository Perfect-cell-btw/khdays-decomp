/* Entity factory: allocates the enemy object, records its class id, opens its Ms/ resource by the
 * formatted class name, installs the class constructor as the state callback (+0x18c) and hands the
 * object to the shared enemy framework. */

extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern int Ov107_OpenCachedResourceByName(char *buf);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov179_020d4900[];
extern void Ov179_Construct(int);

int Ov179_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x3b0);
    *(signed char *)(obj + 0x19c) = 31;
    OS_SPrintf(buf, data_ov179_020d4900, 31);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)Ov179_Construct;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
