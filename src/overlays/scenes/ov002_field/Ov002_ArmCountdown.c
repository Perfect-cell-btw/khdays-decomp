/* Arm the countdown. The kind and the fixed priority 7 are set every time, but
 * the value and the start timestamp only when it is not already running -- an
 * armed countdown keeps its own clock. */
extern unsigned long long OS_GetTick(void);

typedef struct {
    unsigned short wStart;          /* +0 */
    unsigned short wCurrent;        /* +2 */
    unsigned short wKind;           /* +4 */
    unsigned short wPriority;       /* +6 */
    char pad0008[8];
    unsigned long long qwStartedAt; /* +0x10 */
    int bRunning;                   /* +0x18 */
} Ov002Countdown;

void Ov002_ArmCountdown(Ov002Countdown *self, unsigned short value,
                         unsigned short kind) {
    self->wKind = kind;
    self->wPriority = 7;

    if (self->bRunning != 0) {
        return;
    }

    self->wStart = value;
    self->wCurrent = value;
    self->qwStartedAt = OS_GetTick();
    self->bRunning = 1;
}
