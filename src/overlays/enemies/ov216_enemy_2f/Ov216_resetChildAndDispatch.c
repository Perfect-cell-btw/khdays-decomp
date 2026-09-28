/* Refreshes and dispatches the child's callbacks (+0x420), then runs the shared object tick. */

extern void RefreshObjectCallbacks(void *p);
extern void DispatchObjectCallbacks(void *p, int a);
extern void Ov107_ProcessObjectTick(void *this, int a);

void Ov216_resetChildAndDispatch(char *this, int param2) {
    RefreshObjectCallbacks(*(void **)(this + 0x420));
    DispatchObjectCallbacks(*(void **)(this + 0x420), 1);
    Ov107_ProcessObjectTick(this, param2);
}
