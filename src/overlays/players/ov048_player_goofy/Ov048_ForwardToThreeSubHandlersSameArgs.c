/* Advances the character's effect block: the active tracks, the sequence slot and the charge
 * sequence. */

extern void Ov048_UpdateTracksWhileActive();
extern void Ov048_StepSequenceSlot();
extern void Ov048_DriveChargeSequence();

void Ov048_ForwardToThreeSubHandlersSameArgs(int this_, int arg1, int arg2) {
    Ov048_UpdateTracksWhileActive(this_, arg1, arg2);
    Ov048_StepSequenceSlot(this_, arg1, arg2);
    Ov048_DriveChargeSequence(this_, arg1, arg2);
}
