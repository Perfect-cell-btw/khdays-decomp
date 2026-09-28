/* Runs the frame and prepares the fade out: captures the current brightness (or waits for the
 * scene); returns the step that advances after the pause. */

extern void Ov022_UpdateCameraAndViews(int a);
extern int func_0201e428(void);
extern int func_0201e438(void);
extern int Ov002_Scene_IsIdle(void);
extern void Ov002_ResetCameraFraming(void);
extern void Ov002_Scene_SetFlagBit3(void);
extern void Ov022_StateAdvanceAfterPause(void);
extern int data_ov022_020b2e60;

int Ov022_StepCameraInputThenNextState(void) {
    int v;
    Ov022_UpdateCameraAndViews(1);
    v = *(signed char *)(data_ov022_020b2e60 + 0x3e);
    if (v != 0) {
        if (v == 2) {
            if (Ov002_Scene_IsIdle() == 0) return 0;
            Ov002_ResetCameraFraming();
        }
    } else {
        *(int *)(data_ov022_020b2e60 + 0x1c) = func_0201e428() << 0xc;
        *(int *)(data_ov022_020b2e60 + 0x20) = func_0201e438() << 0xc;
        if (Ov002_Scene_IsIdle() == 0) Ov002_Scene_SetFlagBit3();
    }
    return (int)Ov022_StateAdvanceAfterPause;
}
