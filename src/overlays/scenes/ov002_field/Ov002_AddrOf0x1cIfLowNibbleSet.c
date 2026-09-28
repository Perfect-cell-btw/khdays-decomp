int Ov002_AddrOf0x1cIfLowNibbleSet(int p)
{
    return (*(signed char *)(p + 0x40) & 0xf) != 0 ? p + 0x1c : 0;
}
