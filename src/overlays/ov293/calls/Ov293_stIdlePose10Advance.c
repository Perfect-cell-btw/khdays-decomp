extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov293_AdvanceStateSetField18_3();

void Ov293_stIdlePose10Advance(int this_) {
    int n = *(int *)(this_ + 4);
    if (*(unsigned char *)*(int *)(n + 0x4c)) return;
    Ov107_PostTagUpdate(*(int *)n, 0xa, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov293_AdvanceStateSetField18_3);
}
