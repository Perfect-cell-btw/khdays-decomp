/* Releases one hold on sleep mode (gSleepBlockCount, never below zero); returns the remaining count. */

extern int gSleepBlockCount;

int Sleep_Unblock(void) {
    int v = *(short *)&gSleepBlockCount;
    if (v > 0) {
        v -= 1;
        *(short *)&gSleepBlockCount = v;
    }
    return v;
}
