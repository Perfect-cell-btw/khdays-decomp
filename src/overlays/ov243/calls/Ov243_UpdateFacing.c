/* Facing update of the ov241 enemy (x3: ov241/242/243): eases the +4 heading towards the +8
 * target at the +0x28 rate, turns it into a quaternion about the world Y axis for the actor's
 * +0xa0 orientation, shifts the +0x10 offset into the actor's +0xf0 and reloads the zero vector
 * into it (the Ov120_RecomputeNodeVectorAndReloadTriple shape). */
struct vec3 { int x, y, z; };

extern int Angle_TurnToward(int a, int b, int c, int d);
extern void QuatFromAxisAngle(int *out, int *tbl, int r);
extern void Srt_SetRotationQuat(int dst, int *src);
extern int data_02042264;
extern int data_02041dc8;

void Ov243_UpdateFacing(int *this)
{
    int *node = (int *)this[1];
    int scratch[4];
    node[1] = Angle_TurnToward(node[1], node[2], node[10], 0);
    QuatFromAxisAngle(scratch, &data_02042264, node[1]);
    Srt_SetRotationQuat(node[0] + 0xa0, scratch);
    {
        struct vec3 *triple = (struct vec3 *)(node + 4);
        *(struct vec3 *)(node[0] + 0xf0) = *triple;
        *triple = *(struct vec3 *)&data_02041dc8;
    }
}
