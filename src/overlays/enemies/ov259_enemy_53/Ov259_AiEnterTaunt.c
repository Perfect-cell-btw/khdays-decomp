/* Prime the fields, kick anim 0xd, notify 020cd524, then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov259_MirrorPartnerPose(int, int, int);
extern int Ov259_AiStep_QueueAction2OnAnimEnd(int);
void Ov259_AiEnterTaunt(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(signed char *)(owner + 0xac) = 0;
    *(int *)(owner + 0x94) = 0xb4;
    *(int *)(owner + 0x58) = 1;
    Ov107_PostTagUpdate(*(int *)owner, 0xd, 0);
    Ov259_MirrorPartnerPose(param_1, 0xd, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov259_AiStep_QueueAction2OnAnimEnd);
}
