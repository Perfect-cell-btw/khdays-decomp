extern int NNSi_FndGetCurrentRootHeap();
extern void Ov025_InitCampaignMenuContext();
extern int Ov025_ConsumeHeapFlag3Handler();
extern int data_ov025_020b5740;

void * Ov025_AllocContextAndGetHandler(int *arg0) {
    int *h = (int *)NNSi_FndGetCurrentRootHeap();
    Ov025_InitCampaignMenuContext(*arg0);
    *(int **)&data_ov025_020b5740 = h;
    *h = 9;
    return (void *)Ov025_ConsumeHeapFlag3Handler;
}
