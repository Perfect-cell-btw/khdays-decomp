/* Dispatch to Ov009_WalkRecordsAppendMatching with handler Ov009_RecordFilter_Kind4Id10. */
extern unsigned short Ov009_WalkRecordsAppendMatching(int a, int b, int c, void *handler);
extern void Ov009_RecordFilter_Kind4Id10(void);
int Ov009_AppendRecordsKind4Id10(int param_1, int param_2, int param_3) {
    return Ov009_WalkRecordsAppendMatching(param_1, param_2, param_3, (void *)&Ov009_RecordFilter_Kind4Id10);
}
