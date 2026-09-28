/* Returns the signed byte at a fixed offset. */

int Ov002_GetSignedByteAt2(int p)
{
    return *(signed char *)(p + 2);
}
