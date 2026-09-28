/* Destructor: frees the resource tables (+0x388), destroys the model, the child selector, the child
 * and the five part instances, then the base object. */

struct row8 { void *p, *q; };
extern void FreeAllResourceTables(void *p);
extern void DestroyInstance(void *p);
extern void Ov107_DestroyObject(void *this);

void Ov215_destroyObjectSlots(char *this) {
    int i;
    FreeAllResourceTables(this + 0x388);
    *(int *)(this + 0x394) = 0;
    DestroyInstance(*(void **)(this + 0x384));
    DestroyInstance(*(void **)(this + 0x420));
    DestroyInstance(*(void **)(this + 0x3c4));
    for (i = 0; i < 5; i++) {
        DestroyInstance(((struct row8 *)this)[i + 0x88].p);
    }
    Ov107_DestroyObject(this);
}
