/* Advances the character's effect block: the active tracks, the sequence slot and the charge
 * sequence. */

extern void Ov103_UpdateTracksWhileActive();
extern void Ov103_StepSequenceSlot();
extern void Ov103_DriveChargeSequence();

void Ov103_ForwardToThreeSubHandlersSameArgs(int this_, int arg1, int arg2) {
    Ov103_UpdateTracksWhileActive(this_, arg1, arg2);
    Ov103_StepSequenceSlot(this_, arg1, arg2);
    Ov103_DriveChargeSequence(this_, arg1, arg2);
}
