/* Returns the signed byte at a fixed offset. */

int Ov002_GetSignedByteAt3(int p)
{
    return *(signed char *)(p + 3);
}
