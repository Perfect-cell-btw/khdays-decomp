/* Stores a fixed value into the word at a fixed offset. */

void Ov022_ClearWordAt8(int p)
{
    *(int *)(p + 8) = 0;
}
