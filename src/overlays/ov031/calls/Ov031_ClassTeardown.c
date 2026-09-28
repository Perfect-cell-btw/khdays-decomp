extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov031_freeSubitemChannelResources();
extern void Ov022_DestroyRoot();

void Ov031_ClassTeardown(void)
{
    void *p = NNSi_FndGetCurrentRootHeap();
    Ov031_freeSubitemChannelResources(p);
    Ov022_DestroyRoot(p);
}
