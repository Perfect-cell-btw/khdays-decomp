/* Sends one RTC command through PXI channel 5; true when the FIFO accepted it. */
extern int PXI_SendWordByFifo(int channel, int data, int flag);

int RtcSendPxiCommand(int cmd) {
    return PXI_SendWordByFifo(5, (cmd << 8) & 0x7f00, 0) >= 0;
}
