/* Flags the dispatcher, runs the frame, enables the sound listeners and resets the camera; returns
 * the session start step. */

extern int QueryActiveStateOrDelegate(void);
extern void func_ov022_020884ec(unsigned int arg0);
extern void Ov022_SetBit3OnPtr20(int arg0, int arg1);
extern void Ov022_UpdateCameraAndViews(int arg0);
extern void SoundMgr_SetListenersEnabled(int arg0);
extern void Ov002_ResetCameraFraming(void);
extern int data_ov022_020b2e60;
extern void Ov022_StartSessionThenNextStep(void);

int func_ov022_02083844(void) {
    func_ov022_020884ec(QueryActiveStateOrDelegate());
    Ov022_SetBit3OnPtr20(*(int *)(*(int *)&data_ov022_020b2e60 + 8), 1);
    Ov022_UpdateCameraAndViews(1);
    SoundMgr_SetListenersEnabled(1);
    Ov002_ResetCameraFraming();
    return (int)Ov022_StartSessionThenNextStep;
}
