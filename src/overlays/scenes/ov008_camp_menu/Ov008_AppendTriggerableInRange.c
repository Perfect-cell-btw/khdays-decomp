/* Tail-call the shared dispatcher Ov008_WalkRecordsAppendMatching with Ov008_CanTriggerActionInRange as handler. */
extern int Ov008_WalkRecordsAppendMatching(int a, int b, int c, int handler);
extern void Ov008_CanTriggerActionInRange(void);

int Ov008_AppendTriggerableInRange(int param_1, int param_2, int param_3) {
    return Ov008_WalkRecordsAppendMatching(param_1, param_2, param_3, (int)&Ov008_CanTriggerActionInRange);
}
