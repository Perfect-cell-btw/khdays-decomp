extern int QueryActiveStateOrDelegate();
extern int GetEntryField20ByIndex();
extern int data_ov002_0207e768;

int Ov002_Camera_GetPresetHeight(int arg0) {
    QueryActiveStateOrDelegate(arg0);
    GetEntryField20ByIndex();
    return *(int *)((char *)&data_ov002_0207e768 + arg0 * 0xc);
}
