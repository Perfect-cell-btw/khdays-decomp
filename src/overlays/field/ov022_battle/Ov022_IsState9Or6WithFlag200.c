/* Whether the state is 9, or 6 with flag 0x200. */

int Ov022_IsState9Or6WithFlag200(int p)
{
    int t = *(int *)(p + 4);
    if (t == 9)
        goto one;
    if (t != 6)
        goto zero;
    if ((*(int *)p & 0x200) == 0)
        goto zero;
one:
    return 1;
zero:
    return 0;
}
