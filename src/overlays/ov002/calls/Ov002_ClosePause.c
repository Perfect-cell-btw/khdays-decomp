/* Close out the pause, reporting whether the caller may carry on. Nothing paused
 * means yes; otherwise the close-all runs and the follow-up check decides.
 *
 * The close takes the CONSTANT -1, not the paused object: the slot at +0x8c94 is
 * only the gate, and the -1 the ROM builds is used both as the comparand and as
 * the argument. */
extern void Ov002_CancelQueuedLoads(int object);
extern int Ov002_ElementList_IsEmpty(void);

typedef struct {
    char pad0000[0x8c94];
    int nPauseObject;       /* +0x8c94, -1 = none */
} Ov002RootContext;

extern Ov002RootContext *data_ov002_0207fa00;

int Ov002_ClosePause(void) {
    if (data_ov002_0207fa00->nPauseObject != -1) {
        Ov002_CancelQueuedLoads(-1);

        if (Ov002_ElementList_IsEmpty() == 0) {
            return 0;
        }
    }

    return 1;
}
