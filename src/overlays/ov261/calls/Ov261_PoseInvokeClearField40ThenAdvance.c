extern void Ov107_PostTagUpdate();
extern void Ov107_BuildAndSendUpdate();
extern void SetIndexedSlot();
extern void Ov261_stateDualTimerDivide();

void Ov261_PoseInvokeClearField40ThenAdvance(int this_) {
    int node = *(int *)(this_ + 4);
    Ov107_PostTagUpdate(*(int *)node, 1, 1);
    Ov107_BuildAndSendUpdate(*(int *)node, 0x179, 4, *(int *)(node + 4));
    *(int *)(node + 0x40) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov261_stateDualTimerDivide);
}
