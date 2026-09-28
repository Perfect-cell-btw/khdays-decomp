extern int Ov025_WalkRecordsAppendMatching();
extern int Ov025_RecordFilter_Kind4Id10();

int Ov025_AppendRecordsKind4Id10(int arg0, int arg1, int arg2) {
    return Ov025_WalkRecordsAppendMatching(arg0, arg1, arg2, Ov025_RecordFilter_Kind4Id10);
}
