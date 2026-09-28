/* Whether the byte at a fixed offset is zero. */

int Ov022_IsByte2Zero(int p)
{
    return *(unsigned char *)(p + 2) == 0;
}
