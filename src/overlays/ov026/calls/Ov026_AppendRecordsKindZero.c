/* Dispatch to Ov026_WalkRecordsAppendMatching with handler Ov026_RecordFilter_KindZero. */
extern int Ov026_WalkRecordsAppendMatching(int a, int b, int c, void *handler);
extern void Ov026_RecordFilter_KindZero(void);
int Ov026_AppendRecordsKindZero(int param_1, int param_2, int param_3) {
    return Ov026_WalkRecordsAppendMatching(param_1, param_2, param_3, (void *)&Ov026_RecordFilter_KindZero);
}
