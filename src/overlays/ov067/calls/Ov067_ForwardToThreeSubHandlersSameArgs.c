extern void Ov067_UpdateTracksWhileActive();
extern void Ov067_StepSequenceSlot();
extern void Ov067_DriveChargeSequence();

void Ov067_ForwardToThreeSubHandlersSameArgs(int this_, int arg1, int arg2) {
    Ov067_UpdateTracksWhileActive(this_, arg1, arg2);
    Ov067_StepSequenceSlot(this_, arg1, arg2);
    Ov067_DriveChargeSequence(this_, arg1, arg2);
}
