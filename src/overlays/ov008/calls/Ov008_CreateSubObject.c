/* Ov008_CreateSubObject -- allocate an 8-byte title sub-object, instantiate its class into it,
 * and return the object's update entry (Ov008_TopState). */
extern int  NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *dst, int val, unsigned int size);
extern int  InstantiateClass(int class_desc, int arg);   /* InstantiateClass */
extern int  data_ov008_02090fa8;   /* holds the allocated object pointer */
extern int  data_ov008_02090bd4;   /* class descriptor */
extern void Ov008_TopState(void);

int Ov008_CreateSubObject(int param_1) {
    int *blk = (int *)NNSi_FndGetCurrentRootHeap();
    data_ov008_02090fa8 = (int)blk;
    MI_CpuFill8(blk, 0, 8);
    *(int *)data_ov008_02090fa8 = InstantiateClass((int)&data_ov008_02090bd4, param_1);
    return (int)Ov008_TopState;
}
