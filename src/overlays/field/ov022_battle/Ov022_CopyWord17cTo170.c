/* Copies one word of the object into another. */

void Ov022_CopyWord17cTo170(int p)
{
    *(int *)(p + 0x170) = *(int *)(p + 0x17c);
}
