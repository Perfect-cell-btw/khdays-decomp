/* Allocate the 0x39c-byte sub-actor, back-link the owner at +0x390, install its update
 * handler at +0x18c, run the ov107 setup and return it. */
extern int CallocInstance(int size);
extern void func_ov107_020c6624(int a, int b);
extern void Ov225_Construct(void);
int Ov225_Projectile_New(int param_1) {
    int obj = CallocInstance(0x39c);
    *(int *)(obj + 0x390) = param_1;
    *(int *)(obj + 0x18c) = (int)&Ov225_Construct;
    func_ov107_020c6624(obj, 0);
    return obj;
}
