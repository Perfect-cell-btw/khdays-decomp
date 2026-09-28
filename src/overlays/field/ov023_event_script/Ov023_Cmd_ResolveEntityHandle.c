extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);
extern void Slot48_StoreAtCurrentIndex(int ctx, int args);

extern int Ov023_ScriptOpRunEntityAction(int ctx, int args);

/* Script command: resolves operand 0 twice through the handle table, caches the result in the
 * operand block, and falls back to the default step when the action is not ready. */
int Ov023_Cmd_ResolveEntityHandle(int ctx, int args) {
    int entity = ScriptVm_ReadOperandInt(ctx, (void *)args);
    int r;
    ScriptVm_ReadOperandInt(ctx, (void *)(args + 8));
    *(int *)(args + 4) = func_02020d10(ctx, func_02020d10(ctx, entity));
    r = Ov023_ScriptOpRunEntityAction(ctx, args);
    if (r == 0) {
        Slot48_StoreAtCurrentIndex(ctx, args);
    }
    return r;
}
