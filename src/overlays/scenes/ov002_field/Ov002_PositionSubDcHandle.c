/* Creates a record from a template in the field context's tag tracker (+0xdc). */

extern int data_ov002_0207f60c;
extern int Ov002_CreateRecordFromTemplate();

int Ov002_PositionSubDcHandle(int arg0, int arg1, int arg2) {
    return Ov002_CreateRecordFromTemplate(*(int *)&data_ov002_0207f60c + 0xdc, arg0, arg1, arg2);
}
