extern void DestroyInstance(void *obj);
extern void *List_First(void *list);
extern void *List_Next(void *list);
extern void func_ov107_020c3190(void *obj);
extern void NNSi_FndDestroyDoubleList(void *list);
extern void Ov107_DestroyInstance(void *self);

/* Derived destructor: release the sub-object at self+0x9c, then empty the list
 * at self+0x144 (destroying each entry's payload), destroy the list itself, and
 * hand off to Ov107_DestroyInstance for the base teardown.
 *
 * 0x144 is materialised as `movs #0x51; lsls #2` -- that is just how THUMB
 * builds the constant, not a scaled index. */
void Ov107_DestroyNode(char *self) {
    void **entry;

    if (*(void **)(self + 0x9c) != 0) {
        DestroyInstance(*(void **)(self + 0x9c));
    }
    entry = (void **)List_First(self + 0x144);
    if (entry != 0) {
        do {
            func_ov107_020c3190(*entry);
            entry = (void **)List_Next(self + 0x144);
        } while (entry != 0);
    }
    NNSi_FndDestroyDoubleList(self + 0x144);
    Ov107_DestroyInstance(self);
}
