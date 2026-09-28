/* Copies one word of the object into another. */

void Ov022_CopyWord968To958(int p)
{
    *(int *)(p + 0x958) = *(int *)(p + 0x968);
}
