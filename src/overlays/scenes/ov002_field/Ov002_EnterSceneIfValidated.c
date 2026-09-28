/* Scene entry gate: when a validation hook is installed at root + 0x8b94, run it
 * and hand back no step if it refuses. Otherwise arm mode 1 and let
 * Ov002_PollSessionReady have the final say, returning the step at
 * Ov002_BeginMissionRun. */
extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Ov002_SetLazyClassEnabled(int mode);
extern int Ov002_PollSessionReady(void);
extern void Ov002_BeginMissionRun(void);

void *Ov002_EnterSceneIfValidated(void) {
    int (*validate)(void) =
        *(int (**)(void))((char *)NNSi_FndGetCurrentRootHeap() + 0x8b94);

    if (validate != 0 && validate() == 0) {
        return 0;
    }

    Ov002_SetLazyClassEnabled(1);
    if (Ov002_PollSessionReady() == 0) {
        return 0;
    }
    return (void *)&Ov002_BeginMissionRun;
}
