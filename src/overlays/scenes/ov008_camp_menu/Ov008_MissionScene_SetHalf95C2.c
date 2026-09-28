/* Stores halfword +0x95c2 of the mission scene. */

extern char *data_ov008_02090fa4;
void Ov008_MissionScene_SetHalf95C2(int value)
{
    *(unsigned short *)(data_ov008_02090fa4 + 0x95c2) = value;
}
