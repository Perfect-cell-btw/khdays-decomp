/* Publishes the actor's velocity for the step: zero in action 0, the stored vector scaled down in
 * action 1, then copies it into the movement vector (+0xf0). */

extern void ScaleVec3Fx12(int scale, void *src, void *dst);

struct vec3 { int a, b, c; };
extern struct vec3 data_02041dc8;

void Ov147_PublishVelocity_Step(int *node) {
    int *state = (int *)node[1];
    if (*(signed char *)(*state + 0x1c6) == 0) {
        *(struct vec3 *)(state + 2) = data_02041dc8;
    } else if (*(signed char *)(*state + 0x1c6) == 1) {
        ScaleVec3Fx12(0x800, state + 5, state + 2);
    }
    *(struct vec3 *)(*state + 0xf0) = *(struct vec3 *)(state + 2);
}
