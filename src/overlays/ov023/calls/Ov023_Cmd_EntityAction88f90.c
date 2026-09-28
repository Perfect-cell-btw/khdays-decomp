extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);
extern void Slot48_StoreAtCurrentIndex(int ctx, int args);

extern void Ov023_DetachActorModel(void *entity);

/* Script command: looks the entity up from operand 0 and runs the action on it. */
int Ov023_Cmd_EntityAction88f90(int ctx, int args) {
    int id = func_02020d10(ctx, ScriptVm_ReadOperandInt(ctx, (void *)args));
    Ov023_DetachActorModel(*(char **)(*(char **)(ctx + 0x128) + 0x440) + id * 0x1a64);
    return 1;
}
