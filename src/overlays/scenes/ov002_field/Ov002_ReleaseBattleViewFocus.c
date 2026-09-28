/* The mirror of Ov002_TakeBattleViewFocus: same link-state gate (7 or 1, with the state
 * word re-read for the second test), same pair of ov022 lookups -- but the two
 * follow-up flags are swapped, so this is the "release" half. Both handles are
 * latched before either call, which is why the ROM burns r4 and r5. */
extern int Ov002_GetPhaseWord(void);
extern int func_ov022_02083f0c(void);
extern int func_ov022_02083f5c(void);
extern void func_ov022_02086818(int a, int b);
extern void Ov002_SetOrClearFlag200(int a, int b);

void Ov002_ReleaseBattleViewFocus(void) {
    if (Ov002_GetPhaseWord() == 7 || Ov002_GetPhaseWord() == 1) {
        int handle = func_ov022_02083f0c();
        int entry = func_ov022_02083f5c();

        Ov002_SetOrClearFlag200(handle, 0);
        func_ov022_02086818(entry, 1);
    }
}
