struct bf6 { unsigned char lo : 2, hi : 6; };
int Ov022_GetHi6BitsOfByteVia0x20(int p)
{
    return ((struct bf6 *)(*(int *)(p + 0x20)))->hi;
}
