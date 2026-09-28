/* Tail-call the shared dispatcher Ov302_ParseRecordListAppendMatches, supplying
 * Ov302_RecordFilter_InRange as the per-variant handler (4th arg). Returns what
 * Ov302_ParseRecordListAppendMatches returns. */

extern int Ov302_ParseRecordListAppendMatches(void *a, void *b, void *c, void *cb);
extern void Ov302_RecordFilter_InRange(void);

int Ov302_AppendRecordsInRange(void *a, void *b, void *c) {
    return Ov302_ParseRecordListAppendMatches(a, b, c, Ov302_RecordFilter_InRange);
}
