extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov262_FloatHeightTick();

void Ov262_SetPoseClearField3a8ThenAdvanceSlot(int this_) {
    int node = *(int *)(this_ + 4);
    Ov107_PostTagUpdate(*(int *)node, 2, 1);
    *(int *)(*(int *)node + 0x3a8) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov262_FloatHeightTick);
}
