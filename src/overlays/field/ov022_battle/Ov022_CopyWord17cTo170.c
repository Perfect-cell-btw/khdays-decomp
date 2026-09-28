void Ov022_CopyWord17cTo170(int p)
{
    *(int *)(p + 0x170) = *(int *)(p + 0x17c);
}
