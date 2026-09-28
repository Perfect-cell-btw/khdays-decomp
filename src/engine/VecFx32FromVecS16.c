/* Widens a 16-bit vector to a 32-bit one. */

void VecFx32FromVecS16(int r0, short *r1, int *r2)
{
    r2[0] = r1[0];
    r2[1] = r1[1];
    r2[2] = r1[2];
}
