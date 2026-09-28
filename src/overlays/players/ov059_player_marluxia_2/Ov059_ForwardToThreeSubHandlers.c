extern void Ov059_StepSequenceSlot();
extern void Ov059_UpdateTracksByMode();
extern void Ov059_StepAttackSlot();

void Ov059_ForwardToThreeSubHandlers(int this_, int arg1, int arg2) {
    Ov059_StepSequenceSlot(this_, arg1 + 8);
    Ov059_UpdateTracksByMode(this_, arg1, arg2);
    Ov059_StepAttackSlot(this_, arg1, arg2);
}
