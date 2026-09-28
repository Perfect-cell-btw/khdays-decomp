/* If the pointer at (*global slot)+4 is non-null, forward it (with param_1). */
extern void SetMasterBrightnessSub(int arg, int ptr);
extern int data_ov002_0207f62c;

void Ov002_Field_SetSubBrightness(int param_1) {
    int ptr = *(int *)((char *)&data_ov002_0207f62c + 4);
    if (ptr != 0) {
        SetMasterBrightnessSub(param_1, ptr);
    }
}
