extern void *List_First(int x);
extern void *List_Next(int x);
extern void invokeObjCallbackGuarded(int x);
void invokeObjCallbackList(int param_1) {
    void *e = List_First(param_1 + 0x88);
    if (e == 0) return;
    do {
        invokeObjCallbackGuarded(*(int *)e);
        e = List_Next(param_1 + 0x88);
    } while (e != 0);
}
