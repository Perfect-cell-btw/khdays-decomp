/* Stores the value into the word at a fixed offset of the object. */

void Ov025_StoreWordAt0x4a50(int p, int v)
{
    *(int *)(p + 0x4a50) = v;
}
