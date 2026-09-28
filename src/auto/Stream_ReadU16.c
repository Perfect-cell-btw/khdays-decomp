unsigned short Stream_ReadU16(unsigned short **p)
{
    unsigned short *q = *p;
    unsigned short v = *q++;
    *p = q;
    return v;
}
