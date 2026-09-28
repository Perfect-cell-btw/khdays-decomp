extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ByteCode_ResolveOperand(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);

extern void Ov023_ActorStartEffectTimer(void *entity, int value);
extern void Ov023_ActorLoadEffectAnim(void *entity, int value);
extern void Ov023_ResetSubBlockLayout(void *entity, int value);

/* Script command: marks the entity's transform dirty, then applies whichever variant the operand
 * tag selects. */
int Ov023_Cmd_SetEntityTransformA(int ctx, char *args) {
    char *entity = *(char **)(*(char **)(ctx + 0x128) + 0x440)
                   + func_02020d10(ctx, ScriptVm_ReadOperandInt(ctx, args)) * 0x1a64;
    *(int *)(entity + 0x1a28) |= 0x80;
    switch (*(short *)(args + 8)) {
    case 1:
        Ov023_ActorStartEffectTimer(entity, ScriptVm_ReadOperandInt(ctx, args + 8));
        break;
    case 2: {
        int a = ByteCode_ResolveOperand(ctx, args + 8);
        int b = ScriptVm_ReadOperandInt(ctx, args + 0x10);
        if ((*(int *)(entity + 0x1a28) & 0x100) == 0) {
            Ov023_ActorLoadEffectAnim(entity, a);
        }
        Ov023_ResetSubBlockLayout(entity, b);
        break;
    }
    }
    return 1;
}
