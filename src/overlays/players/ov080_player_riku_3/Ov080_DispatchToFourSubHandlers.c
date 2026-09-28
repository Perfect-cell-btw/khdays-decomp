/* Advances the character's four effect handlers: the sequence slot, the projectiles (firing the
 * volley), the emitter state machine and the synced tracks. */

extern void Ov080_StepSequenceSlot(int a, int b, int c);
extern void Ov080_StepProjectilesAndFireVolley(int a, int b, int c);
extern void Ov080_DriveEmitterStateMachine(int a, int b, int c);
extern void Ov080_AdvanceTrackTime(int a, int b, int c);

void Ov080_DispatchToFourSubHandlers(int a0, int a1, int a2) {
    Ov080_StepSequenceSlot(a0, a1, a2);
    Ov080_StepProjectilesAndFireVolley(a0, a1, a2);
    Ov080_DriveEmitterStateMachine(a0, a1 + 0x110, a2);
    Ov080_AdvanceTrackTime(a0, a1 + 0x220, a2);
}
