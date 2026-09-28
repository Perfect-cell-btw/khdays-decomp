/* Ov008_TickMenuAndCheckTransition -- run the menu per-frame input and report a ready transition, ov008.
 * Ticks the menu input/state (Ov008_UpdateMenuInput); the transition check
 * (Ov008_PollMenuBusyState) returns a result code, and only codes 1 (confirm) or 2 (cancel)
 * hand off to the next state function; anything else stays put (0).
 *
 * The non-zero test is a separate guard around a two-label switch. Folding it into one
 * condition lets mwcc prove the zero test redundant and drops an instruction; writing the
 * hand-off as the switch body is also what keeps it inline with the 0 return out of line. */
extern void Ov008_UpdateMenuInput(void);
extern int  Ov008_PollMenuBusyState(void);
extern void Ov008_RefreshMenuAndSynchronizePersistentFlagState(void);

void *Ov008_TickMenuAndCheckTransition(void) {
    int r;

    Ov008_UpdateMenuInput();
    r = Ov008_PollMenuBusyState();
    if (r != 0) {
        switch (r) {
        case 1:
        case 2:
            return (void *)Ov008_RefreshMenuAndSynchronizePersistentFlagState;
        }
    }
    return 0;
}
