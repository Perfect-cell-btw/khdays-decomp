/* Class pfnMethod: frees the subitem channel resources, then destroys the root objects. */

extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov051_refreshSubObjectSlots();
extern void Ov022_DestroyRoot();

void Ov051_ClassTeardown(void)
{
    void *p = NNSi_FndGetCurrentRootHeap();
    Ov051_refreshSubObjectSlots(p);
    Ov022_DestroyRoot(p);
}
