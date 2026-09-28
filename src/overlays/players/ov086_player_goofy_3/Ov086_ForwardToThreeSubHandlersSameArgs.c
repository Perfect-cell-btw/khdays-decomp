/* Advances the character's effect block: the active tracks, the sequence slot and the charge
 * sequence. */

extern void Ov086_UpdateTracksWhileActive();
extern void Ov086_StepSequenceSlot();
extern void Ov086_DriveChargeSequence();

void Ov086_ForwardToThreeSubHandlersSameArgs(int this_, int arg1, int arg2) {
    Ov086_UpdateTracksWhileActive(this_, arg1, arg2);
    Ov086_StepSequenceSlot(this_, arg1, arg2);
    Ov086_DriveChargeSequence(this_, arg1, arg2);
}
