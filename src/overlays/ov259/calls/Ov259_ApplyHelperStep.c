/* Apply the ov259 helper's +0xc step: the owner moves to its +0xb0 position plus the step
 * (020c5c54) and the step resets. */
typedef struct { int x, y, z; } Vec3;

extern void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern void Ov107_MoveNodeAndRelayout(int actor, Vec3 *at);
extern const Vec3 data_02041dc8;

void Ov259_ApplyHelperStep(int *node)
{
    int *state = (int *)node[1];
    Vec3 at;

    VEC_Add((Vec3 *)(*state + 0xb0), (Vec3 *)(state + 3), &at);
    Ov107_MoveNodeAndRelayout(*state, &at);
    *(Vec3 *)(state + 3) = data_02041dc8;
}
