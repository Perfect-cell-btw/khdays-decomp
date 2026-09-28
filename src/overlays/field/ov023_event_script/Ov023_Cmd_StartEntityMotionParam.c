extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);
extern char *ArrayEntryPtrD0(unsigned short index);
extern void Slot48_StoreAtCurrentIndex(int ctx, int args);

extern void Entity_ForwardToSlot(unsigned short id, int a, int b, void *param, int e);

typedef struct { int mode; int arg1; int arg0; int pad1; int pad2; } Ov023MotionParam;

/* Script command: starts the entity's motion. Operands 1 and 2 select the variant; with both zero
 * the motion runs with no parameter block at all. */
int Ov023_Cmd_StartEntityMotionParam(int ctx, int args) {
    int id = func_02020d10(ctx, ScriptVm_ReadOperandInt(ctx, (void *)args));
    int arg0 = ScriptVm_ReadOperandFx32(ctx, (void *)(args + 8));
    int arg1 = ScriptVm_ReadOperandFx32(ctx, (void *)(args + 0x10));
    Ov023MotionParam p;
    Ov023MotionParam *pp = &p;
    if (arg1 == 0) {
        if (arg0 == 0) {
            pp = 0;
        } else {
            p.mode = 2;
            p.arg0 = arg0;
        }
    } else {
        p.mode = 0;
        p.arg0 = arg0;
        p.arg1 = arg1;
    }
    Entity_ForwardToSlot((unsigned short)id, 0, 0, pp, 0);
    return 1;
}
