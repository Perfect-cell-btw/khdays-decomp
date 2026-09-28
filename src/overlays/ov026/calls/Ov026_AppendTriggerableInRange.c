/* Walks the record list appending the records triggerable at value (flag clear, in range, unlock
 * flag set). */

/* Dispatch to Ov026_WalkRecordsAppendMatching with handler Ov026_CanTriggerActionInRange. */
extern int Ov026_WalkRecordsAppendMatching(int a, int b, int c, void *handler);
extern void Ov026_CanTriggerActionInRange(void);
int Ov026_AppendTriggerableInRange(int param_1, int param_2, int param_3) {
    return Ov026_WalkRecordsAppendMatching(param_1, param_2, param_3, (void *)&Ov026_CanTriggerActionInRange);
}
