extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int ScriptVm_ResolveActorIndex(int ctx, int arg);

extern void Ov023_StorePairAt0x15b8(void *entity, int a, int b);

/* Script command: three-operand entity call -- operands 2 and 1 in that read order. */
int Ov023_Cmd_EntityAction895dc(int ctx, int args) {
    int entity = ScriptVm_ReadOperandInt(ctx, (void *)args);
    int b = ScriptVm_ReadOperandInt(ctx, (void *)(args + 0x10));
    int a = ScriptVm_ReadOperandFx32(ctx, (void *)(args + 8));
    Ov023_StorePairAt0x15b8(*(char **)(*(char **)(ctx + 0x128) + 0x440)
                        + ScriptVm_ResolveActorIndex(ctx, entity) * 0x1a64, a, b);
    return 1;
}
