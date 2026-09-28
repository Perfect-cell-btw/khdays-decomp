/* Pick the target of the ov260 actor: the nearest live entity (020cab14) goes to +0x420; with one,
 * +0x68 takes the flat heading from the +0x10 point to its +0x190 point and the flat distance is
 * returned (0 without a target). */
typedef struct { int x, y, z; } Vec3;

extern int Ov107_FindNearestObject(int obj, int kind);
extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int VEC_Normalize(Vec3 *v, Vec3 *out);
extern int func_020050b4(int x, int y);

int Ov260_PickTarget(int *node)
{
    int *state = (int *)node[1];
    Vec3 d;
    int len;

    *(int *)(*state + 0x420) = Ov107_FindNearestObject(*state, 0);
    if (*(int *)(*state + 0x420) == 0) {
        return 0;
    }
    VEC_Subtract((Vec3 *)(*(int *)(*state + 0x420) + 0x190), (Vec3 *)state[4], &d);
    d.y = 0;
    len = VEC_Normalize(&d, &d);
    state[0x1a] = func_020050b4(d.x, d.z);
    return len;
}
