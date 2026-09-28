/* Forward to the sub-object handler at (*global)+0xdc, passing param_1. */
extern int Ov002_SetFlagBit0(int obj, int arg);
extern int data_ov002_0207f60c;

int Ov002_ForwardToSubDc_5(int param_1) {
    return Ov002_SetFlagBit0(*(int *)&data_ov002_0207f60c + 0xdc, param_1);
}
