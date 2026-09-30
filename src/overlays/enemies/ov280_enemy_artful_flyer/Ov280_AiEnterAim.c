/* Set the flip flag (+0x4a=1) and run the pose wrapper (anim 2 on both nodes) with handler 020cdc90. */
extern void Ov280_PlayPoseAnims(int p1, int p2, int p3, int p4, void *handler);
extern void Ov280_UpdateAimPoint(int);
void Ov280_AiEnterAim(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(signed char *)(child + 0x4a) = 1;
    Ov280_PlayPoseAnims(param_1, 2, 2, 0, (void *)&Ov280_UpdateAimPoint);
}
