struct vec3 { int x, y, z; };

extern int Angle_TurnToward(int a, int b, int c, int d);
extern void QuatFromAxisAngle(int *out, int *tbl, int r);
extern void Srt_SetRotationQuat(int dst, int *src);
extern int data_02042264;
extern int data_02041dc8;

// Recompute the node's scalar from its stored triple, build the derived vector
// (into node[0]+0xa0), shift the previous target triple into node[0]+0xf0.. and
// reload the default triple (data_02041dc8) into node[7..9].
void Ov122_RecomputeNodeVectorAndReloadTriple(int *this)
{
    int *node = (int *)this[1];
    int scratch[4];
    node[4] = Angle_TurnToward(node[4], node[5], node[6], 0);
    QuatFromAxisAngle(scratch, &data_02042264, node[4]);
    Srt_SetRotationQuat(node[0] + 0xa0, scratch);
    {
        struct vec3 *triple = (struct vec3 *)(node + 7);
        *(struct vec3 *)(node[0] + 0xf0) = *triple;
        *triple = *(struct vec3 *)&data_02041dc8;
    }
}
