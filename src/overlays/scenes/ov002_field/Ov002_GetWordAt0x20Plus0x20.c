/* Returns the address at a fixed offset of the block the object points to. */

int Ov002_GetWordAt0x20Plus0x20(int p)
{
    return *(int *)(p + 0x20) + 0x20;
}
