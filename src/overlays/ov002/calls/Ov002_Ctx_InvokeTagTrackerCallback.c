extern int data_ov002_0207f60c;
extern int Ov002_TagTracker_InvokeCallback();

int Ov002_Ctx_InvokeTagTrackerCallback(int arg0) {
    return Ov002_TagTracker_InvokeCallback(*(int *)&data_ov002_0207f60c + 0xdc, arg0);
}
