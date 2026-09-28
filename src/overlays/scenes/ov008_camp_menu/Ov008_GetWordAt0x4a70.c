/* Returns the word at a fixed offset of the object. */

int Ov008_GetWordAt0x4a70(int p)
{
    return *(int *)(p + 0x4a70);
}
