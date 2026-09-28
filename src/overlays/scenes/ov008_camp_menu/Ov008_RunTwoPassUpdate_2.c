/* Ov008_RunTwoPassUpdate_2 -- run the two-pass update and report whether either pass did anything.
 * The first pass always runs, for the kind Ov008_GetDescriptor3 names; only if it reported work
 * does the second pass run, for Ov008_GetDescriptor2's kind. Reports true if either did.
 * Ov008_SetWord0And20_2 is primed with Ov008_GetCtxBlock968c's kind first. */
extern int Ov008_GetCtxBlock968c(void);
extern void Ov008_SetWord0And20_2(int obj, int kind);
extern int Ov008_GetDescriptor3(void);
extern int Ov008_ClampTextPosToLimitAndNotify(int obj, int a, int b, int kind);
extern int Ov008_GetDescriptor2(void);

int Ov008_RunTwoPassUpdate_2(int obj, int a, int b) {
    int first;
    int second;

    second = 0;
    Ov008_SetWord0And20_2(obj, Ov008_GetCtxBlock968c());
    first = Ov008_ClampTextPosToLimitAndNotify(obj, a, b, Ov008_GetDescriptor3());
    if (first != 0) {
        second = Ov008_ClampTextPosToLimitAndNotify(obj, a, b, Ov008_GetDescriptor2());
    }
    return first != 0 || second != 0;
}
