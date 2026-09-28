extern void MI_CpuFill8();
extern int MsgDb_FetchRecord();
extern int DispatchByNodeKind();

void Ov025_InitWithDefaultHandlers(unsigned int *arg0, unsigned int *arg1) {
    unsigned int v;
    MI_CpuFill8(arg0, 0, 0xc);
    v = arg1[0];
    if (v == 0) v = (unsigned int)MsgDb_FetchRecord;
    arg0[1] = v;
    v = arg1[1];
    if (v == 0) v = (unsigned int)DispatchByNodeKind;
    arg0[2] = v;
}
