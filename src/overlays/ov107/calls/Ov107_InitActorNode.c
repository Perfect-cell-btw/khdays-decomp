/* Constructs a full actor AI node: base-init, set flag bit 5, install the twelve behaviour
 * callbacks, seed the two scale fields to 0x1000, init the transform at +0xa0, zero the three
 * position vectors (+0xcc/+0xd8/+0xe4), set the team index (1 for local player 0, else 2), attach a
 * fresh sub-object at +0x9c (with its own flag bit 1), set hw60 bit 15, and init the child list.
 */

typedef unsigned short u16;

typedef struct {
    int nX;
    int nY;
    int nZ;
} VecFx32;

extern void Ov107_InitNodeBase(u16 *node);
extern void SrtTransform_SetIdentity(int *transform);
extern short Session_GetLocalPlayerIndex(void);
extern void *ModelNode_New(void);
extern void List_Init(void *list);
extern void Ov107_DestroyNode(void);
extern void Ov107_AiState_ResolveContacts(void);
extern void Ov107_AiState_DispatchModelCallbacks(void);
extern void Ov107_AiState_OnSyncMessage(void);
extern void Ov107_SendPoseMessage(void);
extern void Ov107_AiState_SetVisible(void);
extern void Ov107_AiState_PostTick(void);
extern void Ov107_RegisterChildInRegion(void);
extern void Ov107_RemoveChildFromRegion(void);
extern void Ov107_RollTransformHistory(void);
extern void Ov107_AiState_IntegrateVelocity(void);
extern void Ov107_AiState_HitShapeOverlap(void);
extern const VecFx32 data_02041dc8;

void Ov107_InitActorNode(u16 *node) {
    Ov107_InitNodeBase(node);
    *node |= 0x20;
    *(void **)(node + 4) = (void *)Ov107_DestroyNode;
    *(void **)(node + 6) = (void *)Ov107_AiState_ResolveContacts;
    *(void **)(node + 8) = (void *)Ov107_AiState_DispatchModelCallbacks;
    *(void **)(node + 0xe) = (void *)Ov107_AiState_OnSyncMessage;
    *(void **)(node + 0x12) = (void *)Ov107_SendPoseMessage;
    *(void **)(node + 0xc) = (void *)Ov107_AiState_SetVisible;
    *(void **)(node + 0x1a) = (void *)Ov107_AiState_PostTick;
    *(void **)(node + 0x14) = (void *)Ov107_RegisterChildInRegion;
    *(void **)(node + 0x16) = (void *)Ov107_RemoveChildFromRegion;
    *(void **)(node + 0x22) = (void *)Ov107_RollTransformHistory;
    *(void **)(node + 0x24) = (void *)Ov107_AiState_IntegrateVelocity;
    *(void **)(node + 0x26) = (void *)Ov107_AiState_HitShapeOverlap;
    *(int *)((char *)node + 0x54) = 0x1000;
    *(int *)((char *)node + 0x58) = 0;
    *(int *)((char *)node + 0x5c) = 0x1000;
    SrtTransform_SetIdentity((int *)(node + 0x50));
    *((char *)node + 0x179) = 0;
    *(VecFx32 *)((char *)node + 0xe4) = data_02041dc8;
    *(VecFx32 *)((char *)node + 0xd8) = *(VecFx32 *)((char *)node + 0xe4);
    *(VecFx32 *)((char *)node + 0xcc) = *(VecFx32 *)((char *)node + 0xd8);
    *(int *)((char *)node + 0x50) = Session_GetLocalPlayerIndex() == 0 ? 1 : 2;
    *(void **)((char *)node + 0x9c) = ModelNode_New();
    *(unsigned int *)(*(int *)((char *)node + 0x9c) + 0x5c) |= 2;
    node[0x30] = (u16)((node[0x30] & 0xffff00ff) |
                 ((((unsigned int)node[0x30] << 0x10) >> 0x18 | 0x80) << 0x18) >> 0x10);
    List_Init(node + 0xa2);
}
