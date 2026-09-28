/* SetTagTrackerNodeArmed bound to the tag tracker embedded at +0xdc of the ov002 context. */

extern int data_ov002_0207f60c;
extern int Ov002_CopyRecordFields6to18();

int Ov002_Ctx_SetTagTrackerNodeArmed(int arg0, int arg1) {
    return Ov002_CopyRecordFields6to18(*(int *)&data_ov002_0207f60c + 0xdc, arg0, arg1);
}
