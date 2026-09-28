/* Returns a + 2b + 2cd (an offset into a table of halfword rows). */

int Ov002_Compute_a_2b_2cd(int a, int b, int c, int d)
{
    return a + b * 2 + c * d * 2;
}
