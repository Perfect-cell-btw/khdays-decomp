/* Allocate a 0x44-byte object, initialise it (with this owner) via 020cb28c and return it. */
extern int CallocInstance(int a);
extern void Ov107_TriggerSphere_Init(int a, int b);
int Ov107_CreateTriggerSphere(int param_1) {
    int obj = CallocInstance(0x44);
    Ov107_TriggerSphere_Init(obj, param_1);
    return obj;
}
