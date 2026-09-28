extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov070_freeSubitemChannelResources();
extern void Ov022_DestroyRoot();

void Ov070_ClassTeardown(void)
{
    void *p = NNSi_FndGetCurrentRootHeap();
    Ov070_freeSubitemChannelResources(p);
    Ov022_DestroyRoot(p);
}
