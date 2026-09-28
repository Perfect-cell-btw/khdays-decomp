extern void Srt_SetRotationQuat(void *a, void *b);

struct vec3 { int a, b, c; };
extern struct vec3 data_02041dc8;

void Ov171_SetPoseVecFromStateOrConst(int *node) {
    int *state = (int *)node[1];
    if (*(signed char *)(*state + 0x1c6) == 1) {
        Srt_SetRotationQuat((void *)(*state + 0xa0), state + 8);
    } else {
        *(struct vec3 *)(state + 0xc) = data_02041dc8;
    }
    *(struct vec3 *)(*state + 0xf0) = *(struct vec3 *)(state + 0xc);
}
