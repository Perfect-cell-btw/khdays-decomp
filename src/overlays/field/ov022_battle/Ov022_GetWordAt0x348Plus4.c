/* Returns the address at a fixed offset of the block the object points to. */

int Ov022_GetWordAt0x348Plus4(int p)
{
    return *(int *)(p + 0x348) + 4;
}
