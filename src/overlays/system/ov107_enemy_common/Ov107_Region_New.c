/* Allocate a 0x118-byte object, initialise it (with this owner) via 020c207c and return it. */
extern int CallocInstance(int a);
extern void Ov107_Region_Init(int a, int b);
int Ov107_Region_New(int param_1) {
    int obj = CallocInstance(0x118);
    Ov107_Region_Init(obj, param_1);
    return obj;
}
