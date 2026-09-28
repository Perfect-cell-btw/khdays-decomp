/* Walks the record list appending the records triggerable at value (flag clear, in range, unlock
 * flag set). Returns what Ov302_ParseRecordListAppendMatches returns. */

extern int Ov302_ParseRecordListAppendMatches(void *a, void *b, void *c, void *cb);
extern void Ov302_CanTriggerActionInRange(void);

int Ov302_AppendTriggerableInRange(void *a, void *b, void *c) {
    return Ov302_ParseRecordListAppendMatches(a, b, c, Ov302_CanTriggerActionInRange);
}
