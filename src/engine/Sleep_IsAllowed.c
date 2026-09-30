/* Whether no hold is taken on sleep mode (gSleepBlockCount == 0): main only enters PM_GoSleepMode on
 * a closed lid when it is. */

extern int gSleepBlockCount;

int Sleep_IsAllowed(void) {
    return *(short *)&gSleepBlockCount == 0;
}
