extern char *data_ov008_02090f24;
void Ov008_PacketSentCallback(void)
{
    *(int *)(data_ov008_02090f24 + 0x2c) = 0;
}
