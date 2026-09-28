/* Build a transform in a local from const data_02042264 and the child's +0xc, then drive the
 * pose via Srt_SetRotationQuat. */
struct w4 { int a, b, c, d; };
extern void Quat_FromTwoVectors(struct w4 *out, const void *in, int p);
extern void Srt_SetRotationQuat(int a, struct w4 *b);
extern const struct w4 data_02042264;
void Ov254_HelperD_ApplyOrientation(int param_1) {
    int child = *(int *)(param_1 + 4);
    struct w4 local;
    Quat_FromTwoVectors(&local, &data_02042264, child + 0xc);
    Srt_SetRotationQuat(*(int *)child + 0xa0, &local);
}
