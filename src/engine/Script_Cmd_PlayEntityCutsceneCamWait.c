extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ByteCode_ResolveOperand(int ctx, void *arg);
extern int ScriptVm_ResolveActorIndex(int ctx, int arg);
extern int ParseSlotQuantityId(void *world, int name);
extern int ResCache_Acquire(int a, void *b, int c);
extern void TailForwardTrackEntry_2(int id, int a, int b, int c);
extern void Slot48_StoreAtCurrentIndex(int ctx, int arg);

/* Script command: same as Script_Cmd_PlayEntityCutsceneCam but always yields afterwards, passing the negated entity
 * id (or the "no entity" sentinel) as the resume key. */
int Script_Cmd_PlayEntityCutsceneCamWait(int ctx, char *args) {
    int entity = ScriptVm_ReadOperandInt(ctx, args);
    int name = ByteCode_ResolveOperand(ctx, args + 8);
    int id = ScriptVm_ResolveActorIndex(ctx, entity);
    char *world = *(char **)(ctx + 0x128);
    if (ResCache_Acquire(ParseSlotQuantityId(world, name), world + 0x28, 0) != 0) {
        TailForwardTrackEntry_2((unsigned short)id, *(int *)(*(char **)(ctx + 0x128) + 0x28), 0, 0);
        if (id == 0) {
            Slot48_StoreAtCurrentIndex(ctx, ~0x62);
        } else {
            Slot48_StoreAtCurrentIndex(ctx, -id);
        }
    } else {
        Slot48_StoreAtCurrentIndex(ctx, id);
    }
    return 0;
}
