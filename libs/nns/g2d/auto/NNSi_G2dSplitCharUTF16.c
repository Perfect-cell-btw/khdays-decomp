/* NitroSystem: returns the next UTF-16 character of a string and advances the cursor past it. */

unsigned short NNSi_G2dSplitCharUTF16(unsigned short **ppChar)
{
    unsigned short *q = *ppChar;
    unsigned short v = *q++;
    *ppChar = q;
    return v;
}
