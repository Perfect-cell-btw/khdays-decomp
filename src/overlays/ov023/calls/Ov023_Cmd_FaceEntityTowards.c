extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ByteCode_ResolveOperand(int ctx, void *arg);
extern char *ScriptVm_ResolveOperand(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);
extern char *ArrayEntryPtrD0(unsigned short index);
extern void EntityMgr_ProbeGround(unsigned short id, int a, void *out);
extern int FX_Atan2(int y, int x);
extern int Ov023_TurnActorToward(int ctx, int id, int angle);

typedef struct { int x, y, z; } Ov023Vec3;

/* Script command: turns the entity to face the point named by operand 1 -- either another
 * entity's position or a resolved world point. */
int Ov023_Cmd_FaceEntityTowards(int ctx, char *args) {
    int entity = ScriptVm_ReadOperandInt(ctx, args);
    char *op = ScriptVm_ResolveOperand(ctx, args + 8);
    int id = func_02020d10(ctx, entity);
    Ov023Vec3 here;
    Ov023Vec3 target;
    unsigned short angle;
    if (*(short *)op == 1) {
        target = *(Ov023Vec3 *)(ArrayEntryPtrD0((unsigned short)func_02020d10(ctx,
                     ScriptVm_ReadOperandInt(ctx, op))) + 0xa8);
    } else if (*(short *)op == 2) {
        EntityMgr_ProbeGround((unsigned short)id, ByteCode_ResolveOperand(ctx, op), &target);
    } else {
        return 1;
    }
    here = *(Ov023Vec3 *)(ArrayEntryPtrD0((unsigned short)id) + 0xa8);
    here.x = target.x - here.x;
    here.z = target.z - here.z;
    angle = (unsigned short)(0x13fff - FX_Atan2(here.z, here.x));
    return Ov023_TurnActorToward(ctx, id, angle);
}
