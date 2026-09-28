/* Advances the character's four effect handlers: the sequence slot, the projectiles (firing the
 * volley), the emitter state machine and the synced tracks. */

extern void Ov041_StepSequenceSlot(int a, int b, int c);
extern void Ov041_StepProjectilesAndFireVolley(int a, int b, int c);
extern void Ov041_DriveEmitterStateMachine(int a, int b, int c);
extern void Ov041_AdvanceTrackTime(int a, int b, int c);

void Ov041_DispatchToFourSubHandlers(int a0, int a1, int a2) {
    Ov041_StepSequenceSlot(a0, a1, a2);
    Ov041_StepProjectilesAndFireVolley(a0, a1, a2);
    Ov041_DriveEmitterStateMachine(a0, a1 + 0x110, a2);
    Ov041_AdvanceTrackTime(a0, a1 + 0x220, a2);
}
