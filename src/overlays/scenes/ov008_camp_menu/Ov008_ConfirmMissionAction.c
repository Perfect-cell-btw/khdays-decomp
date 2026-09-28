/* Confirm the selected mission-menu action. While the active record is idle (+0x30 clear), map
 * its pending action code (+0xa4) to a transition -- 2 becomes 1, 5 becomes 4, 7 becomes 0 --
 * and then commit the input latch either way.
 *
 * Parked as a "switch-vs-if tie" claiming a `switch()` makes mwcc pick a jump table. It does
 * not: with three sparse cases mwcc emits exactly the original's compare chain, all three tests
 * up front and the bodies laid out after, with the no-match branch to the commit. The if/else-if
 * the park used is what folds that branch away, because it interleaves each body with its own
 * test. Four bytes, and the switch is the honest shape anyway. */
extern int  Ov008_GetMenuContext(void);
extern void Ov008_BuildActionPage(int rec, int mode);
extern void PlaySound(int a, int b);

void Ov008_ConfirmMissionAction(void) {
    int rec = Ov008_GetMenuContext();
    if (*(int *)(rec + 0x30) != 0) {
        return;
    }
    switch (*(int *)(rec + 0xa4)) {
    case 2: Ov008_BuildActionPage(rec, 1); break;
    case 5: Ov008_BuildActionPage(rec, 4); break;
    case 7: Ov008_BuildActionPage(rec, 0); break;
    }
    PlaySound(0, 3);
}
