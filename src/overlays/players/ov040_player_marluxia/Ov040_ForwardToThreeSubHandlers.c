/* Advances the character's effect block: the sequence slot, the mode-dependent tracks and the
 * attack slot. */

extern void Ov040_StepSequenceSlot();
extern void Ov040_UpdateTracksByMode();
extern void Ov040_StepAttackSlot();

void Ov040_ForwardToThreeSubHandlers(int this_, int arg1, int arg2) {
    Ov040_StepSequenceSlot(this_, arg1 + 8);
    Ov040_UpdateTracksByMode(this_, arg1, arg2);
    Ov040_StepAttackSlot(this_, arg1, arg2);
}
