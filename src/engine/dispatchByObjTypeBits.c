extern int IsKind1Or4(int x);
extern void ChannelBuf_Append(int a, int b, int c, int d);
void dispatchByObjTypeBits(int param_1, int param_2) {
    int t = IsKind1Or4((unsigned int)((unsigned int)*(unsigned short *)param_1 << 0x1a) >> 0x1b);
    ChannelBuf_Append(param_1, param_2, t, 0);
}
