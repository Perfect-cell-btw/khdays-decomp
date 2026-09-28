/* Kick anim 2, run 020d4234, then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov199_SeedDefaultPoseAndAdvance(int, int);
extern int Ov199_FaceTargetThenIdle(int);
void Ov199_AiEnterFaceTarget(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 2, 0);
    Ov199_SeedDefaultPoseAndAdvance(*(int *)owner, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov199_FaceTargetThenIdle);
}
