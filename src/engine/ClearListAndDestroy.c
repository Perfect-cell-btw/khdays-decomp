/* Destroys every node of the list, then the list itself, and frees it. */

extern void *List_First();
extern void DestroyListNode();
extern void NNSi_FndDestroyDoubleList();
extern void FreeInstanceMemory();

void ClearListAndDestroy(int this_) {
    void *r = List_First(this_);
    while (r != 0) {
        DestroyListNode(this_, (int)r);
        r = List_First(this_);
    }
    NNSi_FndDestroyDoubleList(this_);
    FreeInstanceMemory(this_);
}
