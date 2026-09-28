/* Register pSubscriber in pOwner's subscriber list; returns zero. */

extern void Obj_ReplaceRef(int a, int b);
extern int *List_InsertSorted(int a, int b, int c);
int RegisterSubscriberSlot(int param_1, int param_2) {
    int *p;
    Obj_ReplaceRef(param_2, param_1);
    p = List_InsertSorted(param_1 + 0x88, 4, 0x64);
    *p = param_2;
    return 0;
}
