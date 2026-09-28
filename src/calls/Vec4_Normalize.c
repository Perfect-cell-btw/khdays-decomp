/*
 * Vec4_Normalize - normalize a 4-component fx32 vector in place, returning its magnitude.
 *
 * Takes the magnitude of `v` via Quat_Length; if zero, zeroes the output vector `q`,
 * otherwise multiplies each component of q by the reciprocal 1/magnitude (FX_InvFx64c
 * returns it as a 64-bit fixed-point value) using a signed 64x32 multiply-high with
 * round-to-nearest: q[i] = (q[i] * recip + 0x80000000) >> 32. Returns the magnitude.
 *
 * q[3] is assigned in BOTH branches (not lifted to a shared local): that lets mwcc tail-merge
 * the two stores through r0, which also fixes the sign-extend/umull scheduling in the loop body.
 */

extern int Quat_Length(int *v);
extern long long FX_InvFx64c(int x);

int Vec4_Normalize(int *q, int *v)
{
    int mag = Quat_Length(v);

    if (mag != 0) {
        long long recip = FX_InvFx64c(mag);
        q[0] = (int)((recip * q[0] + 0x80000000LL) >> 32);
        q[1] = (int)((recip * q[1] + 0x80000000LL) >> 32);
        q[2] = (int)((recip * q[2] + 0x80000000LL) >> 32);
        q[3] = (int)((recip * q[3] + 0x80000000LL) >> 32);
    } else {
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
    }
    return mag;
}
