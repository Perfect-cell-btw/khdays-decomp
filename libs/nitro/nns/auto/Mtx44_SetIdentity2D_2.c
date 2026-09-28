/* Sets the upper 2x2 block of a 4x4 matrix to identity and its XY translation to 0. */

void Mtx44_SetIdentity2D_2(int *p)
{
    p[0] = 0x1000;
    p[1] = 0;
    p[4] = 0;
    p[5] = 0x1000;
    p[12] = 0;
    p[13] = 0;
}
