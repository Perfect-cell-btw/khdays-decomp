extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov204_AiWaitThenAnim11();

void Ov204_GuardField28Pose10ClearAdvance(int this_) {
    int n = *(int *)(this_ + 4);
    if (*(unsigned char *)*(int *)(n + 0x28)) return;
    Ov107_PostTagUpdate(*(int *)n, 0xa, 1);
    *(int *)(n + 0x2c) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov204_AiWaitThenAnim11);
}
