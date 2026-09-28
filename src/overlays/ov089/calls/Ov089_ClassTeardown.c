extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov089_refreshSubObjectSlots();
extern void Ov022_DestroyRoot();

void Ov089_ClassTeardown(void)
{
    void *p = NNSi_FndGetCurrentRootHeap();
    Ov089_refreshSubObjectSlots(p);
    Ov022_DestroyRoot(p);
}
