extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);
extern void StoreArrayInt244(int index, int value);

/* Script command: resolves the entity from operand 0 and stores operand 1 into its slot. */
int Ov023_Cmd_SetEntitySlot(int ctx, int args) {
    int entity = ScriptVm_ReadOperandInt(ctx, (void *)args);
    int value = ScriptVm_ReadOperandFx32(ctx, (void *)(args + 8));
    StoreArrayInt244((unsigned short)func_02020d10(ctx, entity), value);
    return 1;
}
