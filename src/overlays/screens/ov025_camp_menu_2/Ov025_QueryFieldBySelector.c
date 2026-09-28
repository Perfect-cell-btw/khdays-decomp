/* Recompute the cached value at (param_1)+0x10 from the source at +0x14 using the selector
 * param_2 (0-7) to pick the per-kind conversion; out-of-range selectors are ignored. */
extern int Ov025_AppendRecordsInRange(int a, int b, int arg2);
extern int Ov025_FindBestRecordAppend(int a, int b, unsigned int param_3, unsigned int param_4);
extern int Ov025_AppendRecordsBelowMax(int a, int b, int arg2);
extern int Ov025_AppendEligibleRecords(int a, int b, int arg2);
extern int Ov025_AppendTriggerableInRange(int a, int b, int arg2);
extern int Ov025_AppendRecordsKindZero(int a, int b, int arg2);
extern int Ov025_AppendRecordsKindNonZero(int a, int b, int arg2);
extern int Ov025_AppendRecordsKind4Id10(int a, int b, int arg2);
void Ov025_QueryFieldBySelector(int param_1, int param_2, int arg2, unsigned int arg3) {
    switch (param_2) {
        case 0: *(short *)(param_1 + 0x10) = Ov025_AppendRecordsInRange(param_1, *(int *)(param_1 + 0x14), arg2); break;
        case 1: *(short *)(param_1 + 0x10) = Ov025_FindBestRecordAppend(param_1, *(int *)(param_1 + 0x14), arg2, arg3); break;
        case 2: *(short *)(param_1 + 0x10) = Ov025_AppendRecordsBelowMax(param_1, *(int *)(param_1 + 0x14), arg2); break;
        case 3: *(short *)(param_1 + 0x10) = Ov025_AppendEligibleRecords(param_1, *(int *)(param_1 + 0x14), arg2); break;
        case 4: *(short *)(param_1 + 0x10) = Ov025_AppendTriggerableInRange(param_1, *(int *)(param_1 + 0x14), arg2); break;
        case 5: *(short *)(param_1 + 0x10) = Ov025_AppendRecordsKindZero(param_1, *(int *)(param_1 + 0x14), arg2); break;
        case 6: *(short *)(param_1 + 0x10) = Ov025_AppendRecordsKindNonZero(param_1, *(int *)(param_1 + 0x14), arg2); break;
        case 7: *(short *)(param_1 + 0x10) = Ov025_AppendRecordsKind4Id10(param_1, *(int *)(param_1 + 0x14), arg2); break;
    }
}
