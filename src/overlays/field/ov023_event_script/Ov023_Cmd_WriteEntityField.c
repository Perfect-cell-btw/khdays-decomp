extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);
extern void Slot48_StoreAtCurrentIndex(int ctx, int args);

extern char *ArrayEntryPtrD0(int index);
extern void Anim_SetFrameWrapped(void *p, int slot, int value);

/* Script command: writes operand 2 into slot (operand 1) of the entity from operand 0. */
int Ov023_Cmd_WriteEntityField(int ctx, int args) {
    int entity = ScriptVm_ReadOperandInt(ctx, (void *)args);
    int slot = ScriptVm_ReadOperandInt(ctx, (void *)(args + 8));
    int value = ScriptVm_ReadOperandFx32(ctx, (void *)(args + 0x10));
    Anim_SetFrameWrapped(ArrayEntryPtrD0((unsigned short)func_02020d10(ctx, entity)) + 4,
                  (unsigned short)slot, value);
    return 1;
}
