/* Set or clear bit 3 of the flag byte at +8 from a boolean argument. */

void Obj_SetFlagBit3(void *pP, int flag)
{
    unsigned char *p = (unsigned char *)pP;
    if (flag)
        p[8] |= 8;
    else
        p[8] &= ~8;
}
