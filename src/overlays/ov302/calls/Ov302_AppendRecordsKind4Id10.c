/* Walks the record list appending the records of kind 4 with id (+2) 10. */

extern void Ov302_ParseRecordListAppendMatches(void *a, void *b, void *c, void *cb);
extern void Ov302_RecordFilter_Kind4Id10(void);

void Ov302_AppendRecordsKind4Id10(void *a, void *b, void *c) {
    Ov302_ParseRecordListAppendMatches(a, b, c, Ov302_RecordFilter_Kind4Id10);
}
