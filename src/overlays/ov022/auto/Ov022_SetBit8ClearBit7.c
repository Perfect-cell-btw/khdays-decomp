void Ov022_SetBit8ClearBit7(int p)
{
    *(int *)p = (*(int *)p | 0x100) & ~0x80;
}
