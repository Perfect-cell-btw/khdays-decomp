/* Stores byte +0x95ad of the mission scene. */

extern char *data_ov008_02090fa4;
void Ov008_MissionScene_SetByte95AD(int value)
{
    *(unsigned char *)(data_ov008_02090fa4 + 0x95ad) = value;
}
