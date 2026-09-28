/* Dispatch to Ov005_WalkRecordsAppendMatching with handler Ov005_CanTriggerActionInRange. */
extern int Ov005_WalkRecordsAppendMatching(int a, int b, int c, void *handler);
extern void Ov005_CanTriggerActionInRange(void);
int Ov005_AppendTriggerableInRange(int param_1, int param_2, int param_3) {
    return Ov005_WalkRecordsAppendMatching(param_1, param_2, param_3, (void *)&Ov005_CanTriggerActionInRange);
}
