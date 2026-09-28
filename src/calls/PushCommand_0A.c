extern void PushCommand_impl(int cmd, int a, int b, int c, int d);

void PushCommand_0A(int a, int b, int c) {
    PushCommand_impl(0xa, a, b, c, 0);
}
