/* Advances the character's effect block: the sequence slot, the mode-dependent tracks and the
 * attack slot. */

extern void Ov079_StepSequenceSlot();
extern void Ov079_UpdateTracksByMode();
extern void Ov079_StepAttackSlot();

void Ov079_ForwardToThreeSubHandlers(int this_, int arg1, int arg2) {
    Ov079_StepSequenceSlot(this_, arg1 + 8, arg2);
    Ov079_UpdateTracksByMode(this_, arg1, arg2);
    Ov079_StepAttackSlot(this_, arg1, arg2);
}
