/* Transforms a vector by a rotation: builds the 3x3 matrix of the quaternion and multiplies the
 * vector by it. */

extern void Mtx33_FromQuat(void *mtx);
extern void MTX_MultVec33(void *out, void *mtx, void *in);

void Vec3TransformViaTempMtx(void *in_vec, int unused, void *out_vec)
{
    int mtx_local[9];
    Mtx33_FromQuat(&mtx_local);
    MTX_MultVec33(out_vec, &mtx_local, in_vec);
}
