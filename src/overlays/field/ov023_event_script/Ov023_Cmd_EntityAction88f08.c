extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ByteCode_ResolveOperand(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);
extern char *ArrayEntryPtrD0(int index);

extern void Ov023_ActorStartTrack(void *entity, int a, int b);

/* Script command: two-parameter entity call, operand 1 read through the float accessor. */
int Ov023_Cmd_EntityAction88f08(int ctx, int args) {
    int entity = ScriptVm_ReadOperandInt(ctx, (void *)args);
    int a = ByteCode_ResolveOperand(ctx, (void *)(args + 8));
    int b = ScriptVm_ReadOperandInt(ctx, (void *)(args + 0x10));
    Ov023_ActorStartTrack(*(char **)(*(char **)(ctx + 0x128) + 0x440)
                        + func_02020d10(ctx, entity) * 0x1a64, a, b);
    return 1;
}
