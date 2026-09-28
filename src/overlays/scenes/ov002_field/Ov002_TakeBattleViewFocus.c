/* Hand the ov022 battle handle over to Ov002_SetOrClearFlag200, but only in link
 * states 7 and 1. The state word is re-read for the second comparison instead of
 * being cached -- the ROM calls Ov002_GetPhaseWord twice, so the source tests it
 * twice; caching it into a local costs the second call and the match.
 *
 * The tail is the same three-call sequence as Ov002_BeginRequest: latch the
 * handle first, silence the current entry, then dispatch with follow-up state 1. */
extern int Ov002_GetPhaseWord(void);
extern int func_ov022_02083f0c(void);
extern int func_ov022_02083f5c(void);
extern void func_ov022_02086818(int a, int b);
extern void Ov002_SetOrClearFlag200(int a, int b);

void Ov002_TakeBattleViewFocus(void) {
    if (Ov002_GetPhaseWord() == 7 || Ov002_GetPhaseWord() == 1) {
        int handle = func_ov022_02083f0c();

        func_ov022_02086818(func_ov022_02083f5c(), 0);
        Ov002_SetOrClearFlag200(handle, 1);
    }
}
