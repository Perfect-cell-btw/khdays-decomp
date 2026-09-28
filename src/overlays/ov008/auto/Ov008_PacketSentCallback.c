/* Send completion callback: clears the mission sync context's busy flag (+0x2c). */

extern char *data_ov008_02090f24;
void Ov008_PacketSentCallback(void)
{
    *(int *)(data_ov008_02090f24 + 0x2c) = 0;
}
