/* Advances the character's effect block: the sequence slot, the mode-dependent tracks and the
 * attack slot. */

extern void Ov096_StepSequenceSlot();
extern void Ov096_UpdateTracksByMode();
extern void Ov096_StepAttackSlot();

void Ov096_ForwardToThreeSubHandlers(int this_, int arg1, int arg2) {
    Ov096_StepSequenceSlot(this_, arg1 + 8);
    Ov096_UpdateTracksByMode(this_, arg1, arg2);
    Ov096_StepAttackSlot(this_, arg1, arg2);
}
