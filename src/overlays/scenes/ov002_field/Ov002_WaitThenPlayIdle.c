/* Wait for the state machine to go quiet, then kick the idle animation. The
 * wait is a genuine SPIN: the bne at the end of the poll branches BACKWARDS to
 * the call, not forwards to a return, and the constant 0 argument is parked in a
 * callee-saved register precisely because it has to survive each iteration. */
extern int Ov002_StepCrawlChar(int which);
extern void EnqueueObjGfxCommand(void *animator);

typedef struct {
    char pad0000[0x6f8];
    char animator[1];       /* +0x6f8 */
} Ov002RequestContext;

extern Ov002RequestContext *data_ov002_0207f624;

void Ov002_WaitThenPlayIdle(void) {
    Ov002RequestContext *ctx = data_ov002_0207f624;

    do {
    } while (Ov002_StepCrawlChar(0) != 0);

    EnqueueObjGfxCommand(ctx->animator);
}
