/* Reset the timer (+0x28=0), start the ov107 effect (mode from the s16 at +0x50, kind
 * 0xb, data at +8), then run the pose wrapper (anim 0xd on both nodes) with handler 020cedf4. */
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void Ov265_PlayPoseAnims(int p1, int p2, int p3, int p4, void *handler);
extern void Ov265_AiPoseSequenceTickB(int);
void Ov265_AiEnterPoseSequenceB(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x28) = 0;
    Ov107_BuildAndSendUpdate(*(int *)child, *(short *)(child + 0x50), 0xb, *(int *)(child + 8));
    Ov265_PlayPoseAnims(param_1, 0xd, 0xd, 0, (void *)&Ov265_AiPoseSequenceTickB);
}
