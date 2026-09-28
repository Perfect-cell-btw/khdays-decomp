extern int data_ov002_0207f60c;
extern int Ov002_ApplyTempFieldsAndRestore();

int Ov002_PositionSubDcHandle_3(int arg0, int arg1, int arg2) {
    return Ov002_ApplyTempFieldsAndRestore(*(int *)&data_ov002_0207f60c + 0xdc, arg0, arg1, arg2);
}
