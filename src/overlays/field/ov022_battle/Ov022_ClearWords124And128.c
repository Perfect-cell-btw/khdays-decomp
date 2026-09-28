/* Clears the words at +0x124 and +0x128. */

void Ov022_ClearWords124And128(int p)
{
    *(int *)(p + 0x124) = 0;
    *(int *)(p + 0x128) = 0;
}
