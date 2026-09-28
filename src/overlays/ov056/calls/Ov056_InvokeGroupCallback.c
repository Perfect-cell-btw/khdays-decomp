/* Invokes the callback of the stream group at +0x2644. */

extern void Ov022_InvokeCallback24IfBit0(int arg);

void Ov056_InvokeGroupCallback(char *base) {
    Ov022_InvokeCallback24IfBit0(*(int *)(base + 0x2644));
}
