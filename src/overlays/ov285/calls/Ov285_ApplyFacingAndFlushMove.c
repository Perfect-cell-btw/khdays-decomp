typedef struct {
    int nX;
    int nY;
    int nZ;
} VecFx32;

typedef struct {
    int x;
    int y;
    int z;
    int w;
} Quat;

struct State {
    char *pActor;
    int nAngle04;
    int nAngleTarget08;
    char pad0c[8];
    int nAngleStep14;
    char pad18[4];
    VecFx32 vPending1c;
};

struct Node {
    void *pScene;
    struct State *pState;
};

extern int Angle_TurnToward(int cur, int target, int step, int *pDone);
extern void QuatFromAxisAngle(Quat *out, const VecFx32 *axis, int angle);
extern void Quat_FromTwoVectors(Quat *out, const VecFx32 *a, VecFx32 *b);
extern void Quat_Multiply(Quat *out, Quat *a, Quat *b);
extern void Srt_SetRotationQuat(void *srt, Quat *q);

extern const VecFx32 data_02042264;
extern const VecFx32 data_02041dc8;

void Ov285_ApplyFacingAndFlushMove(struct Node *node)
{
    struct State *st;
    Quat qDelta;
    Quat qFacing;

    st = node->pState;
    st->nAngle04 = Angle_TurnToward(st->nAngle04, st->nAngleTarget08,
                                 st->nAngleStep14, 0);
    QuatFromAxisAngle(&qDelta, &data_02042264, st->nAngle04);
    Quat_FromTwoVectors(&qFacing, &data_02042264, (VecFx32 *)(st->pActor + 0x124));
    Quat_Multiply(&qFacing, &qFacing, &qDelta);
    Srt_SetRotationQuat(st->pActor + 0xa0, &qFacing);
    *(VecFx32 *)(st->pActor + 0xf0) = st->vPending1c;
    st->vPending1c = data_02041dc8;
}
