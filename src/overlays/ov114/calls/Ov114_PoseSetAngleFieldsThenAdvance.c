extern void Ov107_PostTagUpdate();
extern int func_020050b4();
extern void SetIndexedSlot();
extern void Ov114_AiBrakeUntilGrounded();

void Ov114_PoseSetAngleFieldsThenAdvance(int this_) {
    int node = *(int *)(this_ + 4);
    int a;
    Ov107_PostTagUpdate(*(int *)node, 8, 0);
    a = func_020050b4(*(int *)(node + 0x5c), *(int *)(node + 0x64)) + 0x3244;
    *(int *)(node + 0x18) = a;
    *(int *)(node + 0x14) = a;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov114_AiBrakeUntilGrounded);
}
