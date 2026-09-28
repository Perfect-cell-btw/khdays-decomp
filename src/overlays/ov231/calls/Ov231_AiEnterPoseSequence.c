/* Reset the timer (+0x28=0) and run the pose wrapper (anim 0xc on both nodes) with handler 020cecc8. */
extern void Ov231_PlayPoseAnims(int p1, int p2, int p3, int p4, void *handler);
extern void Ov231_AiPoseSequenceTick(int);
void Ov231_AiEnterPoseSequence(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x28) = 0;
    Ov231_PlayPoseAnims(param_1, 0xc, 0xc, 0, (void *)&Ov231_AiPoseSequenceTick);
}
