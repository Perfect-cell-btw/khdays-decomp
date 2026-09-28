/* Stores the value into the word at a fixed offset of the object. */

void Ov015_StoreWordAt0x3c(int p, int v)
{
    *(int *)(p + 0x3c) = v;
}
