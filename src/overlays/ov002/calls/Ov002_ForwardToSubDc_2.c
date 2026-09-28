extern int data_ov002_0207f60c;
extern int Ov002_InvokeCallback40();

int Ov002_ForwardToSubDc_2(int arg0) {
    return Ov002_InvokeCallback40(*(int *)&data_ov002_0207f60c + 0xdc, arg0);
}
