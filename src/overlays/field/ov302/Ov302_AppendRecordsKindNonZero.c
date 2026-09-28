/* Walks the record list appending the records whose kind byte (+0x23) is nonzero. */

extern void Ov302_ParseRecordListAppendMatches(void *a, void *b, void *c, void *cb);
extern void Ov302_RecordFilter_KindNonZero(void);

void Ov302_AppendRecordsKindNonZero(void *a, void *b, void *c) {
    Ov302_ParseRecordListAppendMatches(a, b, c, Ov302_RecordFilter_KindNonZero);
}
