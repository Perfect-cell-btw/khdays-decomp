/* Sets bit 3 of the flags. */

void Ov022_SetBit3IfClear(int p)
{
    if ((*(int *)p & 8) == 0)
        *(int *)p = *(int *)p | 8;
}
