/* Class pfnMethod: releases the bound object and resources, destroys the root objects and clears
 * the instance pointer. */

extern void *NNSi_FndGetCurrentRootHeap(void);
extern int Ov043_ReleaseBoundObject(int param_1);
extern void Ov043_ReleaseMissionBlock(int param_1);
extern void Ov043_ReleaseAndFreeField2644(char *obj);
extern void Ov022_DestroyRoot(char *root);
extern int data_ov043_020b58e0;

void Ov043_ClassTeardown(void) {
    int root = (int)NNSi_FndGetCurrentRootHeap();
    Ov043_ReleaseBoundObject(root);
    Ov043_ReleaseMissionBlock(root);
    Ov043_ReleaseAndFreeField2644((char *)root);
    Ov022_DestroyRoot((char *)root);
    data_ov043_020b58e0 = 0;
}
