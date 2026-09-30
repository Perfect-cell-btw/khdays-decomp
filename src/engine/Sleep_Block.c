/* Takes a hold on sleep mode (gSleepBlockCount) so that closing the lid does not put the console to
 * sleep; returns the new count. The save code holds it around save-card access and releases it with
 * Sleep_Unblock. */

extern int gSleepBlockCount;

int Sleep_Block(void) {
    int v = *(short *)&gSleepBlockCount + 1;
    *(short *)&gSleepBlockCount = v;
    return v;
}
