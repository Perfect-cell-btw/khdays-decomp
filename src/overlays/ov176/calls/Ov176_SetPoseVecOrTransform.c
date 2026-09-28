extern void ScaleVec3Fx12(int scale, void *src, void *dst);
extern void Quat_FromTwoVectors(void *out, void *mtx, void *vec);
extern void Srt_SetRotationQuat(void *a, void *b);

struct vec3 { int a, b, c; };
extern struct vec3 data_02041dc8;
extern int data_02042258;

void Ov176_SetPoseVecOrTransform(int *node) {
    int *state = (int *)node[1];
    unsigned int tmp[4];
    if (*(signed char *)(*state + 0x1c6) == 1) {
        ScaleVec3Fx12(0x600, state + 5, state + 2);
        Quat_FromTwoVectors(tmp, &data_02042258, state + 5);
        Srt_SetRotationQuat((void *)(*state + 0xa0), tmp);
    } else {
        *(struct vec3 *)(state + 2) = data_02041dc8;
    }
    *(struct vec3 *)(*state + 0xf0) = *(struct vec3 *)(state + 2);
}
