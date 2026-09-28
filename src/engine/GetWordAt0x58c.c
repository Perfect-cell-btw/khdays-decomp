/* Returns the word at a fixed offset of the object. */

int GetWordAt0x58c(int p)
{
    return *(int *)(p + 0x58c);
}
