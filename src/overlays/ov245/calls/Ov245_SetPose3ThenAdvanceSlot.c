/* Kick the 3 animation on the object, then dispatch via c634. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov245_Carrier_AiStep_QueueAction2OnAnimEnd(int);
void Ov245_SetPose3ThenAdvanceSlot(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate(*(int *)owner, 3, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov245_Carrier_AiStep_QueueAction2OnAnimEnd);
}
