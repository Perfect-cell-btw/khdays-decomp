/* Reset the timer (+0x28=0), set the phase flags (+0x54=1, +0x4c=1) and run the pose
 * wrapper (anim 8 on both nodes) with handler 020ce750. */
extern void Ov263_PlayPoseAnims(int p1, int p2, int p3, int p4, void *handler);
extern void Ov263_LungeTick_2(int);
void Ov263_AiEnterLungeB(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x28) = 0;
    *(int *)(child + 0x54) = 1;
    *(signed char *)(child + 0x4c) = 1;
    Ov263_PlayPoseAnims(param_1, 8, 8, 0, (void *)&Ov263_LungeTick_2);
}
