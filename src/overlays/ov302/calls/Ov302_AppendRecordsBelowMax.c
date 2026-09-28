/* Walks the record list appending the records whose flag is clear and hi(+8) < value. */

extern void Ov302_ParseRecordListAppendMatches(void *a, void *b, void *c, void *cb);
extern void Ov302_RecordFilter_BelowMax(void);

void Ov302_AppendRecordsBelowMax(void *a, void *b, void *c) {
    Ov302_ParseRecordListAppendMatches(a, b, c, Ov302_RecordFilter_BelowMax);
}
