/* Allocate the 0x198-byte sub-actor, back-link the owner at +0x18c, run the setup and return it. */
extern int CallocInstance(int size);
extern void Ov210_ShieldPartInit(int a, int b);
int Ov210_ShieldPart_New(int param_1) {
    int obj = CallocInstance(0x198);
    *(int *)(obj + 0x18c) = param_1;
    Ov210_ShieldPartInit(obj, param_1);
    return obj;
}
