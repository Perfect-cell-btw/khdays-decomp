/* Stores the value into the word at a fixed offset of the object. */

void Ov005_StoreWordAt0x98(int p, int v)
{
    *(int *)(p + 0x98) = v;
}
