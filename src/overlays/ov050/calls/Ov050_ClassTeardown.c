extern void *NNSi_FndGetCurrentRootHeap();
extern void Ov050_freeSubitemChannelResources();
extern void Ov022_DestroyRoot();

void Ov050_ClassTeardown(void)
{
    void *p = NNSi_FndGetCurrentRootHeap();
    Ov050_freeSubitemChannelResources(p);
    Ov022_DestroyRoot(p);
}
