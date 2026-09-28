/* Allocates a part actor, records its spawner (+0x38c) and its state callback (+0x18c), and hands
 * it to the shared enemy framework. */

extern void *CallocInstance(int size);
extern void func_ov107_020c6624(void *obj, int flag);
extern void Ov175_SubObject_ConstructB(void);

void *Ov175_Actor_New(void *a) {
    void *obj = CallocInstance(0x39c);
    *(void **)((char *)obj + 0x38c) = a;
    *(void **)((char *)obj + 0x18c) = Ov175_SubObject_ConstructB;
    func_ov107_020c6624(obj, 0);
    return obj;
}
