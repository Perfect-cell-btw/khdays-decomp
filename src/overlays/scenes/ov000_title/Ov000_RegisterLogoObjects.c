/* Ov000_RegisterLogoObjects -- register the 10 logo objects with the sub-object manager,
 * ov000. Re-adds each object (heap[0x1301+i]) to the manager @heap[0x6c] via
 * Obj_CommitAlphaBlend, then commits with Obj_CommitAllSlots. */
extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Obj_CommitAlphaBlend(void *mgr, void *obj);
extern void Obj_CommitAllSlots(void *mgr);
void Ov000_RegisterLogoObjects(void) {
    int *h = (int *)NNSi_FndGetCurrentRootHeap();
    int i;
    for (i = 0; i < 10; i++) {
        Obj_CommitAlphaBlend((void *)(h + 0x6c), ((void **)h)[0x1301 + i]);
    }
    Obj_CommitAllSlots((void *)(h + 0x6c));
}
