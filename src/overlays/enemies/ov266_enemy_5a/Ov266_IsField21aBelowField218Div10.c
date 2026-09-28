int Ov266_IsField21aBelowField218Div10(int *obj)
{
    int base = *obj;
    return *(short *)(base + 0x21a) < *(short *)(base + 0x218) / 10;
}
