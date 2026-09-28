extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ByteCode_ResolveOperand(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);

extern void Ov023_ActorRotateJoint(void *entity, int a, int *vec, int b, int c);

/* Script command: seven operands -- three of them are angles scaled by 0xb6 (degrees to the
 * engine's 1/65536-turn units) and passed as a vector. */
int Ov023_Cmd_SetEntityAngles(int ctx, char *args) {
    int entity = ScriptVm_ReadOperandInt(ctx, args);
    int x = ScriptVm_ReadOperandInt(ctx, args + 0x10);
    int y = ScriptVm_ReadOperandInt(ctx, args + 0x18);
    int z = ScriptVm_ReadOperandInt(ctx, args + 0x20);
    int a = ScriptVm_ReadOperandInt(ctx, args + 0x28);
    int b = ScriptVm_ReadOperandInt(ctx, args + 0x30);
    int c = ByteCode_ResolveOperand(ctx, args + 8);
    int id = func_02020d10(ctx, entity);
    int angles[3];
    angles[0] = x * 0xb6;
    angles[1] = y * 0xb6;
    angles[2] = z * 0xb6;
    Ov023_ActorRotateJoint(*(char **)(*(char **)(ctx + 0x128) + 0x440) + id * 0x1a64,
                        c, angles, a, b);
    return 1;
}
