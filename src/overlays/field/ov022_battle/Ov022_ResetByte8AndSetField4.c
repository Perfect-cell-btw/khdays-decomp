extern void Ov022_ResetSlotBytes();
void Ov022_ResetByte8AndSetField4(int arg0, int arg1) {
    *(unsigned char *)(arg0 + 8) = 0;
    Ov022_ResetSlotBytes(arg0);
    *(int *)(arg0 + 4) = arg1;
}
