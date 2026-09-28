extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ByteCode_ResolveOperand(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);
extern char *ArrayEntryPtrD0(int index);

extern void Slot_Spawn(int a, int b, void *vec, int d);

typedef struct { int x, y, z; } Ov023Vec3;

/* Script command: runs the world action from operands 0/1 at the position of the entity named by
 * operand 2. */
int Ov023_Cmd_WorldActionAtEntity(int ctx, int args) {
    int a = ScriptVm_ReadOperandInt(ctx, (void *)args);
    int b = ScriptVm_ReadOperandInt(ctx, (void *)(args + 8));
    char *node = ArrayEntryPtrD0((unsigned short)func_02020d10(ctx,
                     ScriptVm_ReadOperandInt(ctx, (void *)(args + 0x10))));
    Ov023Vec3 pos = *(Ov023Vec3 *)(node + 0xa8);
    Slot_Spawn(a, b, &pos, 0);
    return 1;
}
