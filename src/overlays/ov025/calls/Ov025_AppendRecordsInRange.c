/* Tail-call the shared dispatcher Ov025_WalkRecordsAppendMatching, supplying
 * Ov025_RecordFilter_InRange as the per-variant handler (4th arg). */

extern int Ov025_WalkRecordsAppendMatching();
extern int Ov025_RecordFilter_InRange();

int Ov025_AppendRecordsInRange(int arg0, int arg1, int arg2) {
    return Ov025_WalkRecordsAppendMatching(arg0, arg1, arg2, Ov025_RecordFilter_InRange);
}
