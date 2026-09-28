/* Sort comparison: orders players by score, highest first. */


int Ov003_ComparePlayerScores(unsigned short *a, unsigned short *b)
{
    return b[1] - a[1];
}
