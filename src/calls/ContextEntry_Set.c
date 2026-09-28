extern int *NNSi_FndGetCurrentRootHeap(void);
extern void ContextEntry_InitForRootHeap(void);

void (*ContextEntry_Set(int value))(void)
{
    *NNSi_FndGetCurrentRootHeap() = value;
    return ContextEntry_InitForRootHeap;
}
