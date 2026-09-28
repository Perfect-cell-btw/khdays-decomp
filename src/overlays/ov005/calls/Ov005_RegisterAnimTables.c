extern void Ov005_DestroyMissionList(int table);
extern char data_ov005_0205b814[];
extern char data_ov005_0205b838[];
/* Register both animation tables with the sequencer. */
void Ov005_RegisterAnimTables(void) {
    Ov005_DestroyMissionList((int)data_ov005_0205b814);
    Ov005_DestroyMissionList((int)data_ov005_0205b838);
}
