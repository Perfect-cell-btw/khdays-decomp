void Ov255_SetWordAt0x3ccTo1(int *p)
{
    *(int *)(*p + 0x3cc) = 1;
}
