/* Multi-joint model object constructor: base setup (Node_BaseInit), draw / callback hooks (+0x64
 * DestroySubObjectsAndCleanup, +0x6c InstancedModel_Draw, +0x7c JointModel_DefaultHook7C, +0x80 JointModel_DefaultHook80), a 0x108-byte
 * animation block (+0x88) bound to `res` (12 frames) with the loader's texture flag off during the
 * bind (InstallHandlerPairByFlag), and `count` 0x38-byte joints (+0x8c count, +0x90 array) whose rotations
 * (+8) start as the identity quaternion data_020420f8. */
typedef void (*Callback)(void);

typedef struct {
    int x, y, z, w;
} Quat;

typedef struct {
    char pad00[8];
    Quat rot;               /* 0x08 */
    char pad18[0x38 - 0x18];
} Joint;

struct ModelObj {
    char pad00[0x64];
    Callback draw;          /* 0x64 */
    char pad68[4];
    Callback callback;      /* 0x6c */
    char pad70[0x7c - 0x70];
    Callback hook7c;        /* 0x7c */
    Callback hook80;        /* 0x80 */
    char pad84[4];
    char *anim;             /* 0x88 */
    int jointCount;         /* 0x8c */
    Joint *joints;          /* 0x90 */
};

extern void Node_BaseInit(struct ModelObj *obj, int res);
extern void DestroySubObjectsAndCleanup(void);
extern void InstancedModel_Draw(void);
extern void JointModel_DefaultHook7C(void);
extern void JointModel_DefaultHook80(void);
extern void *CallocInstance(int size);
extern void InstallHandlerPairByFlag(int flag);
extern void RegisterSeqAndInit(char *anim, int res, int a, int frames);
extern const Quat data_020420f8;

void JointModel_Construct(struct ModelObj *obj, int res, int count)
{
    int i;

    Node_BaseInit(obj, res);
    obj->draw = DestroySubObjectsAndCleanup;
    obj->callback = InstancedModel_Draw;
    obj->hook7c = JointModel_DefaultHook7C;
    obj->hook80 = JointModel_DefaultHook80;
    obj->anim = CallocInstance(0x108);
    InstallHandlerPairByFlag(0);
    RegisterSeqAndInit(obj->anim, res, 1, 0xc);
    InstallHandlerPairByFlag(1);
    obj->jointCount = count;
    obj->joints = CallocInstance(count * 0x38);
    for (i = 0; i < obj->jointCount; i++) {
        obj->joints[i].rot = data_020420f8;
    }
}
