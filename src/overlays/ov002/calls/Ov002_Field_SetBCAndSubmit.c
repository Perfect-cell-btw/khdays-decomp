extern int data_ov002_0207f62c;
extern int Ov002_PageSubmitHookNoOp();

int Ov002_Field_SetBCAndSubmit(int arg0) {
    *(int *)(*(int *)((char *)&data_ov002_0207f62c + 4) + 0xbc) = arg0;
    return Ov002_PageSubmitHookNoOp(arg0);
}
