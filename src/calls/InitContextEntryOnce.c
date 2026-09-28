extern void MsgQueue_ResendForPeer(int a);
extern void Node_FlipDoubleBuffer(int a);
extern int *data_0204c230;

void InitContextEntryOnce(int param_1) {
    int *ctx = data_0204c230;
    if (*ctx != 0) return;
    MsgQueue_ResendForPeer(param_1);
    Node_FlipDoubleBuffer(ctx[1] + param_1 * 0x20);
}
