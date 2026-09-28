/* Returns the signed byte at a fixed offset. */

int Ov002_GetSignedByteAt1(int p)
{
    return *(signed char *)(p + 1);
}
