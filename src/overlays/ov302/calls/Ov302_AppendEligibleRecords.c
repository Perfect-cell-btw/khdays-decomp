extern void Ov302_ParseRecordListAppendMatches(void *a, void *b, void *c, void *cb);
extern void Ov302_IsEncounterEligible(void);

void Ov302_AppendEligibleRecords(void *a, void *b, void *c) {
    Ov302_ParseRecordListAppendMatches(a, b, c, Ov302_IsEncounterEligible);
}
