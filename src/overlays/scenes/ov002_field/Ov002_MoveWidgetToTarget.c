/* Reposition the widget when the caller supplies a target: move it to the signed
 * 16-bit coordinates, optionally re-anchor it, and always hand the target on to
 * Ov002_Ctx_SetTagTrackerNodeArmed_5. The fifth argument arrives on the stack and is re-read
 * from there for the final call rather than held. */
extern void Ov002_PositionSubDcHandle_4(void *self, int x, int y);
extern void Ov002_ForwardToSubDc_3(void *self);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(void *self, int target);

void Ov002_MoveWidgetToTarget(void *self, int x, int y, int reanchor, int target) {
    if (target != 0) {
        Ov002_PositionSubDcHandle_4(self, (short)x, (short)y);
        if (reanchor != 0) {
            Ov002_ForwardToSubDc_3(self);
        }
    }

    Ov002_Ctx_SetTagTrackerNodeArmed_5(self, target);
}
