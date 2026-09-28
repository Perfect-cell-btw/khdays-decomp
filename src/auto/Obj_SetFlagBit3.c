void Obj_SetFlagBit3(unsigned char *p, int flag)
{
    if (flag)
        p[8] |= 8;
    else
        p[8] &= ~8;
}
