/* Recompute the cached value at (param_1)+0x10 from the source at +0x14 using the selector
 * param_2 (0-7) to pick the per-kind conversion; out-of-range selectors are ignored. */
extern int Ov005_AppendRecordsInRange(int a, int b);
extern int Ov005_FindBestRecordAppend(int a, int b);
extern int Ov005_AppendRecordsBelowMax(int a, int b);
extern int Ov005_AppendEligibleRecords(int a, int b);
extern int Ov005_AppendTriggerableInRange(int a, int b);
extern int Ov005_AppendRecordsKindZero(int a, int b);
extern int Ov005_AppendRecordsKindNonZero(int a, int b);
extern int Ov005_AppendRecordsKind4Id10(int a, int b);
void Ov005_QueryFieldBySelector(int param_1, int param_2) {
    switch (param_2) {
        case 0: *(short *)(param_1 + 0x10) = Ov005_AppendRecordsInRange(param_1, *(int *)(param_1 + 0x14)); break;
        case 1: *(short *)(param_1 + 0x10) = Ov005_FindBestRecordAppend(param_1, *(int *)(param_1 + 0x14)); break;
        case 2: *(short *)(param_1 + 0x10) = Ov005_AppendRecordsBelowMax(param_1, *(int *)(param_1 + 0x14)); break;
        case 3: *(short *)(param_1 + 0x10) = Ov005_AppendEligibleRecords(param_1, *(int *)(param_1 + 0x14)); break;
        case 4: *(short *)(param_1 + 0x10) = Ov005_AppendTriggerableInRange(param_1, *(int *)(param_1 + 0x14)); break;
        case 5: *(short *)(param_1 + 0x10) = Ov005_AppendRecordsKindZero(param_1, *(int *)(param_1 + 0x14)); break;
        case 6: *(short *)(param_1 + 0x10) = Ov005_AppendRecordsKindNonZero(param_1, *(int *)(param_1 + 0x14)); break;
        case 7: *(short *)(param_1 + 0x10) = Ov005_AppendRecordsKind4Id10(param_1, *(int *)(param_1 + 0x14)); break;
    }
}
