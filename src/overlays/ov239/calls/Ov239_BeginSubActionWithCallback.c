/* Calls Ov239_ConfigSubStateThenAdvanceSlot(this, 2, 0, 1, Ov239_AimAndSteerTick) -- the 5th arg
 * (callback) is passed on the stack. */

extern void Ov239_ConfigSubStateThenAdvanceSlot();
extern void Ov239_AimAndSteerTick();

void Ov239_BeginSubActionWithCallback(int this_) {
    Ov239_ConfigSubStateThenAdvanceSlot(this_, 2, 0, 1, Ov239_AimAndSteerTick);
}
