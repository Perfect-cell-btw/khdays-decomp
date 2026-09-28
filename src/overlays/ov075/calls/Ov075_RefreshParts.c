extern void Ov022_InvokeCallback24IfBit0();

void Ov075_RefreshParts(int this_) {
    int *base = (int *)(this_ + 0x2000);
    int i, off;
    for (i = 0, off = 0; i < 3; i++, off += 0x30) {
        Ov022_InvokeCallback24IfBit0(base[0x191] + off);
    }
}
