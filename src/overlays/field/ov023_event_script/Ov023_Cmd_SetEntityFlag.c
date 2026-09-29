extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ResolveActorIndex(int ctx, int arg);
extern void Slot48_StoreAtCurrentIndex(int ctx, int args);

/* The script VM entity table: ctx->world->entities + id * sizeof(Entity). */

extern void Ov023_Window_SetFlag10(void *entity, int on);

/* Script command: turns a flag on the entity from operand 0 on or off from operand 1. */
int Ov023_Cmd_SetEntityFlag(int ctx, int args) {
    int entity = ScriptVm_ReadOperandInt(ctx, (void *)args);
    int on;
    if (ScriptVm_ReadOperandInt(ctx, (void *)(args + 8)) != 0) {
        on = 1;
    } else {
        on = 0;
    }
    Ov023_Window_SetFlag10(*(char **)(*(char **)(ctx + 0x128) + 0x440)
                        + ScriptVm_ResolveActorIndex(ctx, entity) * 0x1a64, on);
    return 1;
}
