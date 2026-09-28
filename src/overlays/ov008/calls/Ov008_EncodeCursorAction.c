/* Ov008_EncodeCursorAction -- forward a cursor pick to the ov008 scroll widget as an action command.
 * Command = (slot << 8) | action, where action is 7 normally and 8 when the alternate-mode flag
 * (obj+0x14e0) is set. Only runs while a page transition is active (Ov008_GetCtxObject9634 != 0). */
extern int  Ov008_GetMenuContext(void);
extern int  Ov008_GetCtxObject9634(void);
extern void Ov008_RebuildQueryList(int widget, unsigned int cmd);
extern void Ov008_SortListByKey(int obj);

void Ov008_EncodeCursorAction(int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4) {
    int obj = Ov008_GetMenuContext();
    if (Ov008_GetCtxObject9634() == 0) {
        return;
    }
    {
        unsigned int cmd;
        /* The 64-bit OR is what makes mwcc emit the ROM's redundant `orr r1, r5, #0` copy of
         * the slot before the shift: the bit it sets is bit 32, which the narrowing back to
         * `unsigned int` discards, so the value is exactly `param_1` -- but the low half of
         * the 64-bit OR still has to be materialised into its own register. Same family of
         * codegen idioms as `(char *)0 + x` for `add rD, rS, #0`.
         * The set arm is written first so its `orrne` is the one emitted first. */
        unsigned int slot = (unsigned int)((unsigned long long)param_1 | 0x100000000LL);

        if (*(int *)(obj + 0x14e0) != 0) {
            cmd = slot << 8 | 8;
        } else {
            cmd = slot << 8 | 7;
        }
        Ov008_RebuildQueryList(obj + 0x13fc, cmd);
        Ov008_SortListByKey(obj);
    }
}
