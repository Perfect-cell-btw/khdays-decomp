/* Ov006_CreateSubObject -- allocate an 8-byte Mission Mode sub-object, instantiate its class into it,
 * and return the object's update entry (Ov006_TopState). */
extern int  NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *dst, int val, unsigned int size);
extern int  InstantiateClass(int class_desc, int arg);   /* InstantiateClass */
extern int  data_ov006_02056668;   /* holds the allocated object pointer */
extern int  data_ov006_020563e4;   /* class descriptor */
extern void Ov006_TopState(void);

int Ov006_CreateSubObject(int param_1) {
    int *blk = (int *)NNSi_FndGetCurrentRootHeap();
    data_ov006_02056668 = (int)blk;
    MI_CpuFill8(blk, 0, 8);
    *(int *)data_ov006_02056668 = InstantiateClass((int)&data_ov006_020563e4, param_1);
    return (int)Ov006_TopState;
}
