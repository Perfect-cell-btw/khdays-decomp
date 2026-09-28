/* Destructor: destroys the model (+0x384) and every part instance in the table at +0x39c, frees the
 * table, then destroys the base object. */

extern void DestroyInstance();
extern void FreeInstanceMemory();
extern void Ov107_DestroyObject();

struct row8 { int a, b; };

void Ov170_ReleaseSubObjectsListThenNotify(int this_) {
    int i;
    DestroyInstance(*(int *)(this_ + 0x384));
    for (i = 0; i < 4; i++)
        DestroyInstance(((struct row8 *)*(int *)(this_ + 0x39c))[i].a);
    FreeInstanceMemory(*(int *)(this_ + 0x39c));
    Ov107_DestroyObject(this_);
}
