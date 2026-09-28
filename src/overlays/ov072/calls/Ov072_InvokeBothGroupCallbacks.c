extern int Ov022_InvokeCallback24IfBit0();

void Ov072_InvokeBothGroupCallbacks(int *r0) {
    Ov022_InvokeCallback24IfBit0(((int **)((char *)r0 + 0x2644))[0]);
    Ov022_InvokeCallback24IfBit0((char *)((int **)((char *)r0 + 0x2644))[0] + 0x30);
}
