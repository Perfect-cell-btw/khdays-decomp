/* Re-orthonormalises the rotation matrix through a quaternion composed with the fixed rotation. */

extern void Quat_FromMtx33(void *dst, void *ptr);
extern void Vec4_Normalize(void *dst, void *src);
extern void Quat_Multiply(void *dst, void *src, void *arg);
extern void Mtx33_FromQuat(void *ptr, void *src);
extern char data_020420d8;

void Mtx33_ApplyFixedRotation(void *ptr) {
    int tmp[4];

    Quat_FromMtx33(tmp, ptr);
    Vec4_Normalize(tmp, tmp);
    Quat_Multiply(tmp, tmp, &data_020420d8);
    Mtx33_FromQuat(ptr, tmp);
}
