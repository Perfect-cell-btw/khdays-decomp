/* Forward to the sub-object handler at (*global)+0xdc, passing param_1. */
extern int Ov002_IsEntityReady(int obj, int arg);
extern int data_ov002_0207f60c;

int Ov002_ForwardToSubDc_4(int param_1) {
    return Ov002_IsEntityReady(*(int *)&data_ov002_0207f60c + 0xdc, param_1);
}
