/* Stores a fixed value into the word at a fixed offset. */

void SetWordAt0x588To1(int p)
{
    *(int *)(p + 0x588) = 1;
}
