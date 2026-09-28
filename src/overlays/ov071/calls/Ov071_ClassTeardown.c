extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov071_refreshSubObjectSlots();
extern void Ov022_DestroyRoot();

void Ov071_ClassTeardown(void)
{
    void *p = NNSi_FndGetCurrentRootHeap();
    Ov071_refreshSubObjectSlots(p);
    Ov022_DestroyRoot(p);
}
