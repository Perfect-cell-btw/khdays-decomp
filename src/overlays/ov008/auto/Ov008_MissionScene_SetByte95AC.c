extern char *data_ov008_02090fa4;
void Ov008_MissionScene_SetByte95AC(int value)
{
    *(unsigned char *)(data_ov008_02090fa4 + 0x95ac) = value;
}
