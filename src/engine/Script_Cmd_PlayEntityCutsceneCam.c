extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ByteCode_ResolveOperand(int ctx, void *arg);
extern int ScriptVm_ResolveActorIndex(int ctx, int arg);
extern int ParseSlotQuantityId(void *world, int name);
extern int ResCache_Acquire(int a, void *b, int c);
extern void TailForwardTrackEntry_2(int id, int a, int b, int c);
extern void Slot48_StoreAtCurrentIndex(int ctx, int arg);

/* Script command: starts the named cutscene camera on the entity, or yields if the resource is
 * not resident yet. */
int Script_Cmd_PlayEntityCutsceneCam(int ctx, char *args) {
    int entity = ScriptVm_ReadOperandInt(ctx, args);
    int name = ByteCode_ResolveOperand(ctx, args + 8);
    int id = ScriptVm_ResolveActorIndex(ctx, entity);
    char *world = *(char **)(ctx + 0x128);
    if (ResCache_Acquire(ParseSlotQuantityId(world, name), world + 0x28, 0) != 0) {
        TailForwardTrackEntry_2((unsigned short)id, *(int *)(*(char **)(ctx + 0x128) + 0x28), 1, 0);
        return 1;
    }
    Slot48_StoreAtCurrentIndex(ctx, id);
    return 0;
}
