/* Returns a word of the object the object points to at a fixed offset. */

int Ov022_GetWordVia0x20Then0x230(int p)
{
    return *(int *)(*(int *)(p + 0x20) + 0x230);
}
