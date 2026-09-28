extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov033_refreshSubObjectSlots();
extern void Ov022_DestroyRoot();

void Ov033_ClassTeardown(void)
{
    void *p = NNSi_FndGetCurrentRootHeap();
    Ov033_refreshSubObjectSlots(p);
    Ov022_DestroyRoot(p);
}
