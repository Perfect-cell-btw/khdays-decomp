extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);
extern void Slot48_StoreAtCurrentIndex(int ctx, int args);

/* The script VM entity table: ctx->world->entities + id * sizeof(Entity). */

extern void Ov023_ActorFinish_2(void *entity);
extern void SNDi_ProcessEntryAlt(int id);

/* Script command: stops the entity's running sound, if it has one. */
int Ov023_Cmd_StopEntitySound(int ctx, int args) {
    int id = func_02020d10(ctx, ScriptVm_ReadOperandInt(ctx, (void *)args));
    char *tbl = *(char **)(*(char **)(ctx + 0x128) + 0x440);
    if (tbl != 0) {
        char *entity = tbl + id * 0x1a64;
        if (*(int *)(entity + 0x15e0) != 0) {
            Ov023_ActorFinish_2(entity);
        }
    }
    SNDi_ProcessEntryAlt((unsigned short)id);
    return 1;
}
