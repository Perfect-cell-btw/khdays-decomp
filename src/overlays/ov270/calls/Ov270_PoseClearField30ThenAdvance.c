extern void Ov107_PostTagUpdate();
extern void Ov107_StartAnim();
extern void SetIndexedSlot();
extern void Ov270_ChaseTick();

void Ov270_PoseClearField30ThenAdvance(int this_) {
    int node = *(int *)(this_ + 4);
    Ov107_PostTagUpdate(*(int *)node, 2, 1);
    *(int *)(node + 0x30) = 0;
    Ov107_StartAnim(*(int *)(*(int *)node + 0x3d0), 0, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov270_ChaseTick);
}
