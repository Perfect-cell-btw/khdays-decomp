extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);
extern char *ArrayEntryPtrD0(unsigned short index);

typedef struct { int x, y, z; } Ov023Vec3;

/* Script command: sets the entity node's scale. A scalar operand scales all three axes; a vector
 * operand (tag non-zero) takes one component per axis. */
int Ov023_Cmd_SetEntityScale(int ctx, char *args) {
    int entity = ScriptVm_ReadOperandInt(ctx, args);
    int value = ScriptVm_ReadOperandFx32(ctx, args + 8);
    char *node = ArrayEntryPtrD0((unsigned short)func_02020d10(ctx, entity));
    if (*(short *)(args + 0x10) == 0) {
        *(int *)(node + 0xbc) = value;
        *(int *)(node + 0xb8) = *(int *)(node + 0xbc);
        *(int *)(node + 0xb4) = *(int *)(node + 0xb8);
    } else {
        Ov023Vec3 v;
        v.x = value;
        v.y = ScriptVm_ReadOperandFx32(ctx, args + 0x10);
        v.z = ScriptVm_ReadOperandFx32(ctx, args + 0x18);
        *(Ov023Vec3 *)(node + 0xb4) = v;
    }
    return 1;
}
