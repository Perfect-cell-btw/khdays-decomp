extern void Ov239_ConfigSubStateThenAdvanceSlot();
extern void Ov239_AimAndSteerTick();

void Ov239_BeginSubActionWithCallback(int this_) {
    Ov239_ConfigSubStateThenAdvanceSlot(this_, 2, 0, 1, Ov239_AimAndSteerTick);
}
