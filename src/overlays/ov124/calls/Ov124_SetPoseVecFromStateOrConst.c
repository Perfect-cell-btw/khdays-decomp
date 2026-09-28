extern void ScaleVec3Fx12(int scale, void *src, void *dst);

struct vec3 { int a, b, c; };
extern struct vec3 data_02041dc8;

void Ov124_SetPoseVecFromStateOrConst(int *node) {
    int *state = (int *)node[1];
    if (*(signed char *)(*state + 0x1c6) == 0) {
        *(struct vec3 *)(state + 3) = data_02041dc8;
    } else if (*(signed char *)(*state + 0x1c6) == 1) {
        ScaleVec3Fx12(0x480, state + 6, state + 3);
    }
    *(struct vec3 *)(*state + 0xf0) = *(struct vec3 *)(state + 3);
}
