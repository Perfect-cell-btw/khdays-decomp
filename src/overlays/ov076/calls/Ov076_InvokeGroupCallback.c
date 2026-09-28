extern void Ov022_InvokeCallback24IfBit0(int arg);

void Ov076_InvokeGroupCallback(char *base) {
    Ov022_InvokeCallback24IfBit0(*(int *)(base + 0x2644));
}
