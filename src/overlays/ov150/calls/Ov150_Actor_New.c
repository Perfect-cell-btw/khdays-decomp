/* Allocates the 0x3a0-byte actor, records its spawner (+0x38c) and state callback (+0x18c), runs
 * the AiState constructor. */

extern void *CallocInstance(int size);
extern void func_ov107_020c6624(void *obj, int flag);
extern void Ov150_EnemyConstruct(void);

void *Ov150_Actor_New(void *a) {
    void *obj = CallocInstance(0x3a0);
    *(void **)((char *)obj + 0x38c) = a;
    *(void **)((char *)obj + 0x18c) = Ov150_EnemyConstruct;
    func_ov107_020c6624(obj, 0);
    return obj;
}
