extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ResolveActorIndex(int ctx, int arg);
extern void Slot48_StoreAtCurrentIndex(int ctx, int args);

/* The script VM entity table: ctx->world->entities + id * sizeof(Entity). */

extern char *ArrayEntryPtrD0(int index);
extern void BindAnimTrack(void *dst, int kind, void *src, short value);

/* Script command: pushes operand 1 as a type-3 tween onto the entity from operand 0, unless the
 * entity resolves to the "none" handle. */
int Ov023_Cmd_PushEntityTween3(int ctx, int args) {
    int entity = ScriptVm_ReadOperandInt(ctx, (void *)args);
    int value = ScriptVm_ReadOperandInt(ctx, (void *)(args + 8));
    int id = ScriptVm_ResolveActorIndex(ctx, entity);
    if (id != 0x40) {
        char *p = ArrayEntryPtrD0((unsigned short)id);
        BindAnimTrack(p + 4, 3, p + 0xe4, (short)value);
    }
    Slot48_StoreAtCurrentIndex(ctx, args);
    return 0;
}
