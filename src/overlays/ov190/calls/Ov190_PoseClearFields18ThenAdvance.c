extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov190_UpdateAimedHitAction();

void Ov190_PoseClearFields18ThenAdvance(int this_) {
    int node = *(int *)(this_ + 4);
    if (*(unsigned char *)(*(int *)(node + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)node, 0xc, 1);
    *(int *)(node + 0x18) = 0;
    *(unsigned char *)(node + 0x3c) = 0;
    *(unsigned char *)(node + 0x3d) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov190_UpdateAimedHitAction);
}
