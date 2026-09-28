/* Tail-call WM_EndKeySharing on the sub-object at param_1+0x1414, passing
 * Ov008_CompareByField6ThenField18 as the teardown callback.
 *
 * The branch target is the pool word loaded into r12, which the original fills
 * with 0x0205697c; Ov008_CompareByField6ThenField18 is the second pool word and arrives in r1
 * as the callback argument. */
extern int func_ov008_0205697c(int obj, int callback);
extern void Ov008_CompareByField6ThenField18(void);

int Ov008_SortListByKey(int param_1) {
    return func_ov008_0205697c(param_1 + 0x1414, (int)&Ov008_CompareByField6ThenField18);
}
