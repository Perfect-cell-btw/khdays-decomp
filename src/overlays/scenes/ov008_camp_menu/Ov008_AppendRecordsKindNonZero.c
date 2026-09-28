/* Tail-call the shared dispatcher Ov008_WalkRecordsAppendMatching with Ov008_RecordFilter_KindNonZero as handler. */
extern int Ov008_WalkRecordsAppendMatching(int a, int b, int c, int handler);
extern void Ov008_RecordFilter_KindNonZero(void);

int Ov008_AppendRecordsKindNonZero(int param_1, int param_2, int param_3) {
    return Ov008_WalkRecordsAppendMatching(param_1, param_2, param_3, (int)&Ov008_RecordFilter_KindNonZero);
}
