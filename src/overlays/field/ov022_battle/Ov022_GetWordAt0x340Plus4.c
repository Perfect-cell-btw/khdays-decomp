/* Returns the address at a fixed offset of the block the object points to. */

int Ov022_GetWordAt0x340Plus4(int p)
{
    return *(int *)(p + 0x340) + 4;
}
