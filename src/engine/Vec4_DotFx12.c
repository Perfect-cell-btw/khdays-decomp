/*
 * Vec4_DotFx12 - Q12 fixed-point dot product of two 4-component vectors.
 *
 * Sum over the four components of FX_Mul(a[i], b[i]) = (a[i]*b[i] + 0x800) >> 12
 * (round-to-nearest fx32 multiply). Used by the quaternion slerp Quat_Slerp to
 * measure the cosine between two quaternions.
 */

int Vec4_DotFx12(int *a, int *b)
{
    return (int)(((long long)a[0] * b[0] + 0x800) >> 0xc)
         + (int)(((long long)a[1] * b[1] + 0x800) >> 0xc)
         + (int)(((long long)a[2] * b[2] + 0x800) >> 0xc)
         + (int)(((long long)a[3] * b[3] + 0x800) >> 0xc);
}
