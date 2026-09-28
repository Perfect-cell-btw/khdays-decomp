extern void Ov097_StepSequenceSlot(int a, int b, int c);
extern void Ov097_StepProjectilesAndFireVolley(int a, int b, int c);
extern void Ov097_DriveEmitterStateMachine(int a, int b, int c);
extern void Ov097_AdvanceTrackTime(int a, int b, int c);

void Ov097_DispatchToFourSubHandlers(int a0, int a1, int a2) {
    Ov097_StepSequenceSlot(a0, a1, a2);
    Ov097_StepProjectilesAndFireVolley(a0, a1, a2);
    Ov097_DriveEmitterStateMachine(a0, a1 + 0x110, a2);
    Ov097_AdvanceTrackTime(a0, a1 + 0x220, a2);
}
