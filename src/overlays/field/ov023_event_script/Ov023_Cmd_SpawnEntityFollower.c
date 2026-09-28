extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ByteCode_ResolveOperand(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);

extern void LoadArrayU8At0ce(unsigned short id);
extern void Ov023_ReadTargetPosition(int ctx, char *args, int id, void *out);
extern void Ov023_StoreEntityTransform(void *entity, void *out, int a, int b);
extern int Ov023_Window_SetFlag4(void *entity, int on);

typedef struct { int a, b, c; } Ov023Spawn;

/* Script command: spawns the entity's follower at the resolved transform and enables or disables
 * its automatic update depending on the trailing operand. */
int Ov023_Cmd_SpawnEntityFollower(int ctx, char *args) {
    int entity = ScriptVm_ReadOperandInt(ctx, args);
    int a = ScriptVm_ReadOperandInt(ctx, args + 0x38);
    int b = ScriptVm_ReadOperandFx32(ctx, args + 0x28);
    int id;
    Ov023Spawn out;
    ScriptVm_ReadOperandFx32(ctx, args + 0x30);
    id = func_02020d10(ctx, entity);
    LoadArrayU8At0ce((unsigned short)id);
    Ov023_ReadTargetPosition(ctx, args, id, &out);
    Ov023_StoreEntityTransform(*(char **)(*(char **)(ctx + 0x128) + 0x440) + id * 0x1a64, &out, b, a);
    if (*(short *)(args + 0x40) != 0) {
        return Ov023_Window_SetFlag4(*(char **)(*(char **)(ctx + 0x128) + 0x440) + id * 0x1a64, 0);
    }
    return Ov023_Window_SetFlag4(*(char **)(*(char **)(ctx + 0x128) + 0x440) + id * 0x1a64, 1);
}
