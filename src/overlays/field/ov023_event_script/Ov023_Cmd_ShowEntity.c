extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int ScriptVm_ResolveActorIndex(int ctx, int arg);

extern void Entity_SetVisible(int id, int on);
extern void Ov023_Window_SetFlag8IfOpen(void *entity, int on);

/* Script command: toggles the entity's visibility both on its graphics node and, when it is
 * actually spawned, on the entity itself. */
int Ov023_Cmd_ShowEntity(int ctx, int args) {
    int id = ScriptVm_ResolveActorIndex(ctx, ScriptVm_ReadOperandInt(ctx, (void *)args));
    char *tbl;
    Entity_SetVisible((unsigned short)id, 1);
    tbl = *(char **)(*(char **)(ctx + 0x128) + 0x440);
    if (tbl != 0) {
        char *entity = tbl + id * 0x1a64;
        if (*(int *)(entity + 0x15e0) != 0) {
            Ov023_Window_SetFlag8IfOpen(entity, 1);
        }
    }
    return 1;
}
