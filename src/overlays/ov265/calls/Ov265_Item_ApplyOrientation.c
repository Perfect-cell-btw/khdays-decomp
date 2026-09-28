/* For sub-state 1, build a transform in a local via 0202ed60 (from const data_02042258 and
 * *(child)+0x390) and drive the pose via Srt_SetRotationQuat. Then copy the child's +8 vector into
 * *(child)+0xf0. */
struct w3 { int a, b, c; };
struct w4 { int a, b, c, d; };
extern void Quat_FromTwoVectors(struct w4 *out, const void *in, int p);
extern void Srt_SetRotationQuat(int a, struct w4 *b);
extern const struct w4 data_02042258;
void Ov265_Item_ApplyOrientation(int param_1) {
    int child = *(int *)(param_1 + 4);
    struct w4 local;
    if (*(signed char *)(*(int *)child + 0x1c6) == 1) {
        Quat_FromTwoVectors(&local, &data_02042258, *(int *)child + 0x390);
        Srt_SetRotationQuat(*(int *)child + 0xa0, &local);
    }
    *(struct w3 *)(*(int *)child + 0xf0) = *(struct w3 *)(child + 8);
}
