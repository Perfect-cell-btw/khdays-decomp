/* Reapplies the edits of an element of the field context's tag tracker (+0xdc) and commits them. */

extern int data_ov002_0207f60c;
extern int Ov002_ReapplyEditsAndCommit();

int Ov002_PositionSubDcHandle_4(int arg0, int arg1, int arg2) {
    return Ov002_ReapplyEditsAndCommit(*(int *)&data_ov002_0207f60c + 0xdc, arg0, arg1, arg2);
}
