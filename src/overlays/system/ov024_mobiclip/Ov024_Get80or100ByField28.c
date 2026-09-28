/* Returns the stream's block size (0x80 or 0x100), or 0 when there is none. */

int Ov024_Get80or100ByField28(int p)
{
    if (*(int *)(p + 0x20) == 0)
        return 0;
    if (*(int *)(p + 0x28) != 0)
        return 0x80;
    return 0x100;
}
