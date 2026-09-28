typedef struct {
    int x;
    int y;
    int z;
} Vec3;

typedef struct {
    int m[9];
} Mtx33;

/* The stored yaw the whole scene is drawn at, as a sine and cosine pair. */
extern short data_0203e210[2];

/* The engine's sine and cosine table: entry n is at [n * 2] and [n * 2 + 1]. */
extern short data_0203d210[];

extern int VEC_Normalize(const Vec3 *v, Vec3 *pUnit);
extern void MTX_RotY33_(Mtx33 *pMtx, short nSin, short nCos);
extern void MTX_MultVec33(const Vec3 *v, const Mtx33 *pMtx, Vec3 *pOut);
extern void func_01ff9044(Mtx33 *pMtx, const Vec3 *pAxis, short nSin,
                          short nCos);
extern void ScaleVec3Fx12(int nFactor, const Vec3 *pSrc, Vec3 *pDst);

/* Turn a direction into a spread offset of a given length.
 *
 * The direction is flattened to the ground plane and normalised, rotated into
 * the scene's yaw frame, then tilted around that frame's own axis by the angle
 * whose index is the caller's step shifted right by four, and finally
 * normalised again and scaled out to the requested length.
 */
void Ov002_BuildSpreadOffset(const Vec3 *pDir, int nLength, int nStep, Vec3 *pOut)
{
    Mtx33 mtx;
    Vec3 vAxis;
    Vec3 vDir;
    int nAngle;

    vDir = *pDir;
    vDir.y = 0;
    VEC_Normalize(&vDir, &vDir);

    MTX_RotY33_(&mtx, data_0203e210[0], data_0203e210[1]);
    MTX_MultVec33(&vDir, &mtx, &vAxis);

    nAngle = nStep >> 4;
    func_01ff9044(&mtx, &vAxis, data_0203d210[nAngle * 2],
                  data_0203d210[nAngle * 2 + 1]);
    MTX_MultVec33(&vDir, &mtx, &vDir);

    VEC_Normalize(&vDir, &vDir);
    ScaleVec3Fx12(nLength, &vDir, &vDir);

    *pOut = vDir;
}
