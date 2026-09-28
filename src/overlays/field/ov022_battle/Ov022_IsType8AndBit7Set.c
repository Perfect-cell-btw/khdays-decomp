/* Whether the type is 8 and flag 0x80 is set. */

int Ov022_IsType8AndBit7Set(int p)
{
    if (*(int *)(p + 4) == 8) {
        if (*(int *)p & 0x80)
            return 1;
    }
    return 0;
}
