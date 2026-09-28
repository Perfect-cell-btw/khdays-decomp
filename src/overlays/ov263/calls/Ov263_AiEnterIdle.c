/* Run the pose wrapper (anim 1 on both nodes) with handler 020cd920. */
extern void Ov263_PlayPoseAnims(int p1, int p2, int p3, int p4, void *handler);
extern void Ov263_AiIdleTick(int);
void Ov263_AiEnterIdle(int param_1) {
    Ov263_PlayPoseAnims(param_1, 1, 1, 0, (void *)&Ov263_AiIdleTick);
}
