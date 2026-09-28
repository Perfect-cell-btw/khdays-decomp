extern volatile int data_ov008_02090f04[];
void Ov008_SetCtxFields9638And963a(int x, int y)
{
    *(unsigned short *)(data_ov008_02090f04[1] + 0x9638) = x;
    *(unsigned short *)(data_ov008_02090f04[1] + 0x963a) = y;
}
