/* Run the local setup (020cc9e0), set up the paired-pose sub-state (+0x28=0, +0x54=1,
 * +0x4c=1) and run the pose wrapper (anim 7 on both nodes) with handler 020ce4b0. */
extern void Ov280_AcquireTarget(int);
extern void Ov280_PlayPoseAnims(int p1, int p2, int p3, int p4, void *handler);
extern void Ov280_LungeTick(int);
void Ov280_AiEnterLunge(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov280_AcquireTarget(param_1);
    *(int *)(child + 0x28) = 0;
    *(int *)(child + 0x54) = 1;
    *(signed char *)(child + 0x4c) = 1;
    Ov280_PlayPoseAnims(param_1, 7, 7, 0, (void *)&Ov280_LungeTick);
}
