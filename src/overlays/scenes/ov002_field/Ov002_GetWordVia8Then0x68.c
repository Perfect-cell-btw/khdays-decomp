/* Returns a word of the object the object points to at a fixed offset. */

int Ov002_GetWordVia8Then0x68(int p)
{
    return *(int *)(*(int *)(p + 8) + 0x68);
}
