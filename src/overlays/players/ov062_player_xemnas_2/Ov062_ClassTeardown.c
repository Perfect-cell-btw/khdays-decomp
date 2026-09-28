/* Class pfnMethod: releases the bound object and resources, destroys the root objects and clears
 * the instance pointer. */

extern int NNSi_FndGetCurrentRootHeap();extern int Ov062_ReleaseBoundObject();extern void Ov062_ReleaseMissionBlock();extern void Ov062_ReleaseAndFreeField2644();extern void Ov022_DestroyRoot();extern int data_ov062_020b80e0;
void Ov062_ClassTeardown(void) {
    int r = NNSi_FndGetCurrentRootHeap();
    Ov062_ReleaseBoundObject(r);
    Ov062_ReleaseMissionBlock(r);
    Ov062_ReleaseAndFreeField2644(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov062_020b80e0 = 0;
}
