/* Returns 1 when a == b or c is nonzero, otherwise 0. */

int Ov002_EqualOrNonzero(int a, int b, int c)
{
    if (a == b) goto one;
    if (c == 0) goto zero;
one:
    return 1;
zero:
    return 0;
}
