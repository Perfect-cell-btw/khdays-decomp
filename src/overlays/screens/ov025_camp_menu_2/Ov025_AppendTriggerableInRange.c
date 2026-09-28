/* Walks the record list appending the records triggerable at value (flag clear, in range, unlock
 * flag set). */

extern unsigned short Ov025_WalkRecordsAppendMatching();
extern int Ov025_CanTriggerActionInRange();

int Ov025_AppendTriggerableInRange(int arg0, int arg1, int arg2) {
    return Ov025_WalkRecordsAppendMatching(arg0, arg1, arg2, Ov025_CanTriggerActionInRange);
}
