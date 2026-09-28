/* Returns base (+0x54) + index * stride (+0x4e). */

int Ov002_MulTagAtField4ePlusField54(int p, int b)
{
    return *(unsigned short *)(p + 0x4e) * b + *(int *)(p + 0x54);
}
