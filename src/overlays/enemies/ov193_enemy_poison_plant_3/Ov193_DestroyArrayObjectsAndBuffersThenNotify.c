/* Teardown: destroy primary sub-object (0x384), destroy 4-entry object array (0x3a0), free array +
 * 0x3a4 buffer via FreeInstanceMemory, then notify parent (Ov107_DestroyObject). */

struct row8 { int a, b; };
extern void DestroyInstance(int p);
extern void FreeInstanceMemory(int p);
extern void Ov107_DestroyObject(int p);

void Ov193_DestroyArrayObjectsAndBuffersThenNotify(int this_) {
    int i;
    DestroyInstance(*(int *)(this_ + 0x384));
    for (i = 0; i < 4; i++) {
        DestroyInstance(((struct row8 *)(*(int *)(this_ + 0x3a0)))[i].a);
    }
    FreeInstanceMemory(*(int *)(this_ + 0x3a0));
    FreeInstanceMemory(*(int *)(this_ + 0x3a4));
    Ov107_DestroyObject(this_);
}
