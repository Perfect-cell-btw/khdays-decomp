extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int ScriptVm_ResolveActorIndex(int ctx, int arg);
extern char *ArrayEntryPtrD0(int index);
extern void Slot48_StoreAtCurrentIndex(int ctx, int args);

extern void NNS_G3dMdlSetMdlAlphaAll(int anim, int frame);

/* Script command: seeks the entity's animation to operand 1 (12.4 fixed point). Operand 3 asks the
 * command to block until the animation finishes. */
int Ov023_Cmd_SeekEntityAnim(int ctx, int args) {
    int entity = ScriptVm_ReadOperandInt(ctx, (void *)args);
    int wait = ScriptVm_ReadOperandInt(ctx, (void *)(args + 0x18));
    int frame = ScriptVm_ReadOperandFx32(ctx, (void *)(args + 8));
    int id = ScriptVm_ResolveActorIndex(ctx, entity);
    NNS_G3dMdlSetMdlAlphaAll(*(int *)(ArrayEntryPtrD0((unsigned short)id) + 0x7c), frame >> 12);
    if (wait == 0) {
        return 1;
    }
    *(int *)(args + 4) = id;
    *(int *)(args + 0x24) = wait;
    Slot48_StoreAtCurrentIndex(ctx, args);
    return 0;
}
