extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ByteCode_ResolveOperand(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int ScriptVm_ResolveActorIndex(int ctx, int arg);
extern int LoadArrayU8At0ce(int id);
extern void Entity_SubmitRenderNode(int a, int b, int c, void *d);
extern void Ov023_PlaceActorModel(void *entity, int a, void *d, int h, int id);
extern void Ov023_ActorAttachToParent(void *entity, void *target, int a, int b);
extern char data_02041dc8;

/* Script command: links the entity to a second one through the shared attach descriptor and
 * starts the follow behaviour. Operand 3, when present, overrides the default blend time. */
int Ov023_Cmd_AttachEntityToEntity(int ctx, char *args) {
    int e1 = ScriptVm_ReadOperandInt(ctx, args);
    int e2 = ScriptVm_ReadOperandInt(ctx, args + 8);
    int blend = 0xa4;
    int value = ByteCode_ResolveOperand(ctx, args + 0x10);
    int id1 = ScriptVm_ResolveActorIndex(ctx, e1);
    int id2 = ScriptVm_ResolveActorIndex(ctx, e2);
    int handle = LoadArrayU8At0ce((unsigned short)id2);
    Entity_SubmitRenderNode((unsigned short)id1, (unsigned short)handle, 0, &data_02041dc8);
    if (*(short *)(args + 0x18) != 0) {
        blend = ScriptVm_ReadOperandFx32(ctx, args + 0x18);
    }
    Ov023_PlaceActorModel(*(char **)(*(char **)(ctx + 0x128) + 0x440) + id1 * 0x1a64,
                        0, &data_02041dc8, handle, id1);
    Ov023_ActorAttachToParent(*(char **)(*(char **)(ctx + 0x128) + 0x440) + id1 * 0x1a64,
                        *(char **)(*(char **)(ctx + 0x128) + 0x440) + id2 * 0x1a64,
                        value, blend);
    return 1;
}
