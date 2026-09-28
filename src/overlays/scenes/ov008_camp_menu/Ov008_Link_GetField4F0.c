/* Read the byte at +0x4f0 of the ov008 global object. */

extern char *data_ov008_02090f24;
int Ov008_Link_GetField4F0(void)
{
    return *(unsigned char *)(data_ov008_02090f24 + 0x4f0);
}
