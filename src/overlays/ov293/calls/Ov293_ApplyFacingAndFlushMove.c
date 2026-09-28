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

typedef struct {
    char pad00[0x44];
    int nWake;         /* 0x44 */
} OvThread;

typedef struct {
    int nAccum;       /* 0x00 */
    int nLastWake;    /* 0x04 */
    int nActive;      /* 0x08 */
} Counter;

typedef struct {
    char pad00[0x2c];
    int nDelta;        /* 0x2c */
} Scene;

struct State {
    char *pActor;        /* 0x00 */
    char pad04[8];
    int nAngle;            /* 0x0c */
    int nAngleTarget;       /* 0x10 */
    int nAngleStep;          /* 0x14 */
    char pad18[4];
    VecFx32 vPending;         /* 0x1c */
};

struct Node {
    Scene *pScene;
    struct State *pState;
};

extern OvThread *func_ov107_020c9848(void);
extern int Angle_TurnToward(int cur, int target, int step, int *pDone);
extern void QuatFromAxisAngle(Quat *out, const VecFx32 *axis, int angle);
extern void Srt_SetRotationQuat(void *srt, Quat *q);

extern Counter data_ov293_020d3660;
extern const VecFx32 data_02042264;
extern const VecFx32 data_02041dc8;

void Ov293_ApplyFacingAndFlushMove(struct Node *node)
{
    struct State *st;
    Quat qDelta;

    st = node->pState;
    if (data_ov293_020d3660.nActive != 0) {
        if (data_ov293_020d3660.nLastWake != func_ov107_020c9848()->nWake) {
            data_ov293_020d3660.nLastWake = func_ov107_020c9848()->nWake;
            data_ov293_020d3660.nAccum += node->pScene->nDelta;
            if (data_ov293_020d3660.nAccum > 0x2000) {
                data_ov293_020d3660.nActive = 0;
            }
        }
    }
    st->nAngle = Angle_TurnToward(st->nAngle, st->nAngleTarget, st->nAngleStep, 0);
    QuatFromAxisAngle(&qDelta, &data_02042264, st->nAngle);
    Srt_SetRotationQuat(st->pActor + 0xa0, &qDelta);
    *(VecFx32 *)(st->pActor + 0xf0) = st->vPending;
    st->vPending = data_02041dc8;
}
