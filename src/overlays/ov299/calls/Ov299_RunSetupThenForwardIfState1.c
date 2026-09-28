extern void Ov107_MoveNodeAndRelayout();
extern void Ov299_AimAtTarget();

void Ov299_RunSetupThenForwardIfState1(int this_, int arg1, int arg2, int arg3) {
    Ov107_MoveNodeAndRelayout(this_, arg1);
    if (*(int *)(this_ + 0x50) != 1) return;
    Ov299_AimAtTarget(*(int *)(this_ + 0x214), arg2, arg3);
}
