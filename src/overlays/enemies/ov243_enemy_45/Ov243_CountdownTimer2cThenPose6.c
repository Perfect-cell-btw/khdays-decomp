extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov243_ConfigSubStateThenAdvanceSlot_2();

void Ov243_CountdownTimer2cThenPose6(int this_) {
    int a = *(int *)this_;
    int b = *(int *)(this_ + 4);
    int obj;
    *(int *)(b + 0x2c) = *(int *)(b + 0x2c) - *(int *)(a + 0x2c);
    obj = *(int *)b;
    if (*(unsigned char *)(*(int *)(obj + 0x384) + 0xad) != 0) return;
    Ov107_PostTagUpdate(obj, 6, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov243_ConfigSubStateThenAdvanceSlot_2);
}
