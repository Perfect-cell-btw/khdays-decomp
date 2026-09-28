/* Whether the word at +0x32c is not negative. */

int Ov022_IsWord0x32cNonNegative(int p)
{
    int r = 0;
    if (*(int *)(p + 0x32c) >= 0)
        r = 1;
    return r;
}
