/* Ov025_RunTwoPassUpdate -- run the two-pass update and report whether either pass did anything.
 * The first pass always runs, for the kind Ov025_GetDescriptor3 names; only if it reported work
 * does the second pass run, for Ov025_GetDescriptor2's kind. Reports true if either did.
 * Ov025_SetWord0And20 is primed with Ov025_GetCtxBlock968c's kind first. */
extern int Ov025_GetCtxBlock968c(void);
extern void Ov025_SetWord0And20(int obj, int kind);
extern int Ov025_GetDescriptor3(void);
extern int Ov025_ClampValueToLimitAndNotify(int obj, int a, int b, int kind);
extern int Ov025_GetDescriptor2(void);

int Ov025_RunTwoPassUpdate(int obj, int a, int b) {
    int first;
    int second;

    second = 0;
    Ov025_SetWord0And20(obj, Ov025_GetCtxBlock968c());
    first = Ov025_ClampValueToLimitAndNotify(obj, a, b, Ov025_GetDescriptor3());
    if (first != 0) {
        second = Ov025_ClampValueToLimitAndNotify(obj, a, b, Ov025_GetDescriptor2());
    }
    return first != 0 || second != 0;
}
