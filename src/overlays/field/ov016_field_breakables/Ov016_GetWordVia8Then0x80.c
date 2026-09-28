/* Returns a word of the object the object points to at a fixed offset. */

int Ov016_GetWordVia8Then0x80(int p)
{
    return *(int *)(*(int *)(p + 8) + 0x80);
}
