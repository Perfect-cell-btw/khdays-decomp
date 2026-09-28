/* Walks the record list appending the records triggerable at value (flag clear, in range, unlock
 * flag set). */

/* Dispatch to Ov009_WalkRecordsAppendMatching with handler Ov009_CanTriggerActionInRange. */
extern int Ov009_WalkRecordsAppendMatching(int a, int b, int c, void *handler);
extern void Ov009_CanTriggerActionInRange(void);
int Ov009_AppendTriggerableInRange(int param_1, int param_2, int param_3) {
    return Ov009_WalkRecordsAppendMatching(param_1, param_2, param_3, (void *)&Ov009_CanTriggerActionInRange);
}
