/* Clears the element's two state bytes and its word at +0x160. */

void Ov025_ClearBytes01AndWord160(int p)
{
    *(char *)(p + 1) = 0;
    *(char *)(p + 0) = 0;
    *(int *)(p + 0x160) = 0;
}
