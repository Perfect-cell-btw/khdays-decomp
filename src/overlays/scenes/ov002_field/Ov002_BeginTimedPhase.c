/* Begin the timed phase: mark it running and start the timer. A solo machine has
 * no phase to time, so it reports done straight away. */
extern int Session_IsReady(void);
extern int Ov002_StepTimedPhase(void);

typedef struct {
    unsigned int dwFlags;       /* +0 */
} Ov002TimingConfig;

extern Ov002TimingConfig *data_ov002_0207fa08;

int Ov002_BeginTimedPhase(void) {
    Ov002TimingConfig *ctx = data_ov002_0207fa08;

    if (Session_IsReady() == 0) {
        return 1;
    }

    ctx->dwFlags |= 4;
    return Ov002_StepTimedPhase();
}
