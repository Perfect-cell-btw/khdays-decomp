extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);

extern void Entity_SetVisible(int id, int on);
extern void Ov023_Window_SetFlag8IfOpen(void *entity, int on);

/* Script command: toggles the entity's visibility both on its graphics node and, when it is
 * actually spawned, on the entity itself. */
int Ov023_Cmd_HideEntity(int ctx, int args) {
    int id = func_02020d10(ctx, ScriptVm_ReadOperandInt(ctx, (void *)args));
    char *tbl;
    Entity_SetVisible((unsigned short)id, 0);
    tbl = *(char **)(*(char **)(ctx + 0x128) + 0x440);
    if (tbl != 0) {
        char *entity = tbl + id * 0x1a64;
        if (*(int *)(entity + 0x15e0) != 0) {
            Ov023_Window_SetFlag8IfOpen(entity, 0);
        }
    }
    return 1;
}
