/* c634 handler: reset two sub-objects (obj->f4 and obj->f8): clear their +0x5c bit 1
 * and re-arm them (SetSubitemState(sub, 0/2, 0, 1); RefreshObjectCallbacks(obj->f4, 0)); clear
 * obj->f28; then dispatch via SetIndexedSlot. sub-objects re-read per use. */
extern void SetSubitemState(int obj, int a, int b, int c);
extern void RefreshObjectCallbacks(int obj, int a);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov159_AiDescentProbe(void);
void Ov159_Reaction_ResetTwoSubObjects(int self) {
    int obj = *(int *)(self + 4);
    *(int *)(*(int *)(obj + 4) + 0x5c) &= ~2;
    SetSubitemState(*(int *)(obj + 4), 0, 0, 1);
    SetSubitemState(*(int *)(obj + 4), 2, 0, 1);
    RefreshObjectCallbacks(*(int *)(obj + 4), 0);
    *(int *)(obj + 0x28) = 0;
    *(int *)(*(int *)(obj + 8) + 0x5c) &= ~2;
    SetSubitemState(*(int *)(obj + 8), 0, 0, 1);
    SetSubitemState(*(int *)(obj + 8), 2, 0, 1);
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov159_AiDescentProbe);
}
