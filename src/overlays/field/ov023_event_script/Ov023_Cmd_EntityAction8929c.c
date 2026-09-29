extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ByteCode_ResolveOperand(int ctx, void *arg);
extern int ScriptVm_ResolveActorIndex(int ctx, int arg);

extern void Ov023_ActorQueueSound(void *entity, int a, int b, int mode, int extra);

/* Script command: five-operand entity call. Mode 1 ignores the last operand. */
int Ov023_Cmd_EntityAction8929c(int ctx, char *args) {
    int entity = ScriptVm_ReadOperandInt(ctx, args);
    int a = ScriptVm_ReadOperandInt(ctx, args + 8);
    int b = ScriptVm_ReadOperandInt(ctx, args + 0x10);
    int mode = ScriptVm_ReadOperandInt(ctx, args + 0x18);
    int extra = ScriptVm_ReadOperandInt(ctx, args + 0x20);
    int id = ScriptVm_ResolveActorIndex(ctx, entity);
    if (mode == 1) {
        Ov023_ActorQueueSound(*(char **)(*(char **)(ctx + 0x128) + 0x440) + id * 0x1a64,
                            a, b, mode, 0);
    } else {
        Ov023_ActorQueueSound(*(char **)(*(char **)(ctx + 0x128) + 0x440) + id * 0x1a64,
                            a, b, mode, extra);
    }
    return 1;
}
