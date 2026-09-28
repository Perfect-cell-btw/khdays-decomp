extern void ChannelBuf_Append();
extern int data_0204c22c;

void SubmitEntryIfActive(int arg0) {
    if (data_0204c22c == 0) return;
    if (*(unsigned short *)(arg0 + 2) != 0) return;
    if (*(int *)(arg0 + 0xc) == 0) return;
    ChannelBuf_Append(*(int *)(arg0 + 0xc),
                  *(unsigned short *)(arg0 + 0x10),
                  *(unsigned short *)(arg0 + 0x12) + 1,
                  1);
}
