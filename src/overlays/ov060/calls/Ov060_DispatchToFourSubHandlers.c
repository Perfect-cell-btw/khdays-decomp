extern void Ov060_StepSequenceSlot(int a, int b, int c);
extern void Ov060_StepProjectilesAndFireVolley(int a, int b, int c);
extern void Ov060_DriveEmitterStateMachine(int a, int b, int c);
extern void Ov060_AdvanceTrackTime(int a, int b, int c);

void Ov060_DispatchToFourSubHandlers(int a0, int a1, int a2) {
    Ov060_StepSequenceSlot(a0, a1, a2);
    Ov060_StepProjectilesAndFireVolley(a0, a1, a2);
    Ov060_DriveEmitterStateMachine(a0, a1 + 0x110, a2);
    Ov060_AdvanceTrackTime(a0, a1 + 0x220, a2);
}
