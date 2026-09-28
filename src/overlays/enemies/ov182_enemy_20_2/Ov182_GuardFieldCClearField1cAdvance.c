extern void SetIndexedSlot();
extern void Ov182_ChargeUpTick();

void Ov182_GuardFieldCClearField1cAdvance(int this_) {
    int n = *(int *)(this_ + 4);
    if (*(unsigned char *)*(int *)(n + 0xc)) return;
    *(int *)(n + 0x1c) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov182_ChargeUpTick);
}
