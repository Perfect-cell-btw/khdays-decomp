/* Stores byte +0x9520 of the mission scene. */

extern char *data_ov008_02090fa4;
void Ov008_MissionScene_SetByte9520(int value)
{
    *(unsigned char *)(data_ov008_02090fa4 + 0x9520) = value;
}
