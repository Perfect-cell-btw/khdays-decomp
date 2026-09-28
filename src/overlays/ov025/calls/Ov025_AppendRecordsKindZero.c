extern int Ov025_WalkRecordsAppendMatching();
extern int Ov025_RecordFilter_KindZero();

int Ov025_AppendRecordsKindZero(int arg0, int arg1, int arg2) {
    return Ov025_WalkRecordsAppendMatching(arg0, arg1, arg2, Ov025_RecordFilter_KindZero);
}
