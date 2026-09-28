extern void Ov107_MoveNodeAndRelayout();
extern void Ov107_ProcessObjectTick();

void Ov179_ConfigureSubObjectThenForward(int this_, int arg1) {
    int sub = *(int *)(this_ + 0x388);
    Ov107_MoveNodeAndRelayout(this_, sub + 0xb0, sub);
    Ov107_ProcessObjectTick(this_, arg1);
}
