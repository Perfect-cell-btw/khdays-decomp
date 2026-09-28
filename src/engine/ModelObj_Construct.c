/* Model-object constructor: base setup (Node_BaseInit), the draw / callback / release hooks
 * (+0x64 DestroySubObjectsAndCleanup2, +0x6c Obj_RenderModel, +0x68 Obj_AdvanceGauges), a 0x108-byte animation block
 * (+0x88, CallocInstance) bound to `res` (RegisterSeqAndInit, 12 frames) and started (SceneNode_SetFlag40); its
 * +0xe0 part is kept in +0x8c, bit 0 of +0xb2 cleared and the five channel weights (+0x94) reset
 * to 1.0 with their +0xa8 / +0xad bytes cleared. */
typedef unsigned char u8;
typedef void (*Callback)(void);

struct ModelObj {
    char pad00[0x64];
    Callback draw;          /* 0x64 */
    Callback release;       /* 0x68 */
    Callback callback;      /* 0x6c */
    char pad70[0x88 - 0x70];
    char *anim;             /* 0x88 */
    char *animPart;         /* 0x8c */
    int field90;            /* 0x90 */
    int weight[5];          /* 0x94 */
    u8 chanA[5];            /* 0xa8 */
    u8 chanB[5];            /* 0xad */
    u8 flagsB2;             /* 0xb2 */
};

extern void Node_BaseInit(struct ModelObj *obj, int res);
extern void DestroySubObjectsAndCleanup2(void);
extern void Obj_RenderModel(void);
extern void Obj_AdvanceGauges(void);
extern char *CallocInstance(int size);
extern void RegisterSeqAndInit(char *anim, int res, int a, int frames);
extern void SceneNode_SetFlag40(char *anim, int a);

void ModelObj_Construct(struct ModelObj *obj, int res)
{
    int i;

    Node_BaseInit(obj, res);
    obj->draw = DestroySubObjectsAndCleanup2;
    obj->callback = Obj_RenderModel;
    obj->release = Obj_AdvanceGauges;
    obj->field90 = 0;
    obj->anim = CallocInstance(0x108);
    RegisterSeqAndInit(obj->anim, res, 1, 0xc);
    SceneNode_SetFlag40(obj->anim, 1);
    obj->animPart = obj->anim + 0xe0;
    obj->flagsB2 &= ~1;
    for (i = 0; i < 5; i++) {
        obj->weight[i] = 0x1000;
        obj->chanA[i] = 0;
        obj->chanB[i] = 0;
    }
}
