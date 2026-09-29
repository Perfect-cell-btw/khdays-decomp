extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int ScriptVm_ResolveActorIndex(int ctx, int arg);
extern char *ArrayEntryPtrD0(int index);
extern void Slot48_StoreAtCurrentIndex(int ctx, int args);

extern void EntityMgr_SetTransition(int id, int kind, int value);
extern void NNS_G3dMdlSetMdlPolygonIDAll(int anim, int flags);

/* Script command: starts animation kind 1 with operand 1 as its parameter and restarts playback.
 * Operand 3 asks the command to block until it finishes. */
int Ov023_Cmd_PlayEntityAnimKind1(int ctx, int args) {
    int entity = ScriptVm_ReadOperandInt(ctx, (void *)args);
    int wait = ScriptVm_ReadOperandInt(ctx, (void *)(args + 0x18));
    int value = ScriptVm_ReadOperandFx32(ctx, (void *)(args + 8));
    int id = ScriptVm_ResolveActorIndex(ctx, entity);
    char *node = ArrayEntryPtrD0((unsigned short)id);
    /* Written as a mask where another call truncates with a cast: mwcc would otherwise compute the
     * truncation once and keep it, while the ROM truncates again at each call. */
    EntityMgr_SetTransition(id & 0xffff, 1, value);
    NNS_G3dMdlSetMdlPolygonIDAll(*(int *)(node + 0x7c), 0x3f);
    if (wait == 0) {
        return 1;
    }
    *(int *)(args + 4) = id;
    *(int *)(args + 0x24) = wait;
    Slot48_StoreAtCurrentIndex(ctx, args);
    return 0;
}
