/* Stores a pair of words into the object. */

void Ov002_StorePairAt0x44(int p, int a, int b)
{
    *(int *)(p + 0x44) = a;
    *(int *)(p + 0x48) = b;
}
