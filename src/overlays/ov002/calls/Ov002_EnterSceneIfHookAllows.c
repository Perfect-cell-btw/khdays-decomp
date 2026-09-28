/* Scene entry gate: run the validation hook installed at +0x8b90 and give up if
 * it refuses, then let Ov002_PollSessionReady have a say. Only in phase 9, and only
 * while Session_IsActive agrees, does it un-quiesce first. Returns the step at
 * Ov002_RetireSubFlow, or nothing on either refusal. +0x8b58 is the phase word
 * Ov002_GetPhaseWord reads. */
extern void *NNSi_FndGetCurrentRootHeap(void);
extern int Ov002_PollSessionReady(void);
extern int Session_IsActive(void);
extern void Ov002_SetLazyClassEnabled(int mode);
extern void Ov002_RetireSubFlow(void);

void *Ov002_EnterSceneIfHookAllows(void) {
    char *root = NNSi_FndGetCurrentRootHeap();

    if ((*(int (**)(void))(root + 0x8b90))() != 0) {
        if (Ov002_PollSessionReady() == 0) {
            return 0;
        }
        if (*(int *)(root + 0x8b58) == 9 && Session_IsActive() != 0) {
            Ov002_SetLazyClassEnabled(1);
        }
        return (void *)&Ov002_RetireSubFlow;
    }
    return 0;
}
