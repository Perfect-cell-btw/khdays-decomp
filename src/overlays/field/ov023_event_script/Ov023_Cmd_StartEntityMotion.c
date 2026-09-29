extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ResolveActorIndex(int ctx, int arg);
extern void Slot48_StoreAtCurrentIndex(int ctx, int args);

/* The script VM entity table: ctx->world->entities + id * sizeof(Entity). */

extern void Ov023_ActorQueueMotion(void *entity, int a, int b, int c, int d, int e);

/* Script command: starts the default motion on the entity from operand 0 with operand 1 as its
 * parameter. */
int Ov023_Cmd_StartEntityMotion(int ctx, int args) {
    int entity = ScriptVm_ReadOperandInt(ctx, (void *)args);
    int param = ScriptVm_ReadOperandInt(ctx, (void *)(args + 8));
    Ov023_ActorQueueMotion(*(char **)(*(char **)(ctx + 0x128) + 0x440)
                        + ScriptVm_ResolveActorIndex(ctx, entity) * 0x1a64, 0, -2, param, 0, 0);
    return 1;
}
