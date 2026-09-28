/* Destroys a registry node: runs its teardown callback unless it was already finished, frees its
 * state block and removes it from the list. */

extern void FreeInstanceMemory();
extern void List_RemoveByHandle();

void DestroyListNode(int this_, int node) {
    void (*cb)(int) = *(void (**)(int))(node + 0x18);
    if (cb != 0 && *(int *)(node + 0x14) == 0) {
        cb(node);
    }
    FreeInstanceMemory(*(int *)(node + 4));
    List_RemoveByHandle(this_, node);
}
