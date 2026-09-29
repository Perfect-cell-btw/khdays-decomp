/* Whether no hold is taken on sleep mode (data_0204bda0 == 0): main only enters PM_GoSleepMode on
 * a closed lid when it is. */

extern int data_0204bda0;

int Sleep_IsAllowed(void) {
    return *(short *)&data_0204bda0 == 0;
}
