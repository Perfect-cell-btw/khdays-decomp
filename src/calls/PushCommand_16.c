extern void PushCommand_impl(int cmd, int a, int b, int c, int d);

void PushCommand_16(int x) {
    PushCommand_impl(0x16, x, 0, 0, 0);
}
