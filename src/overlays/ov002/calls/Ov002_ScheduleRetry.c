/* Pick the retry delay from the elapsed counter: still under 10000 ticks means
 * wait another 0x338, past it means stop waiting. Tail call. */
extern int FSi_BindCardTransfer(int delay);

typedef struct {
    char pad0000[2];
    unsigned short wElapsed;    /* +2 */
} Ov002RetryState;

extern Ov002RetryState data_0204c240;

int Ov002_ScheduleRetry(void) {
    return FSi_BindCardTransfer(data_0204c240.wElapsed >= 10000 ? 0 : 0x338);
}
