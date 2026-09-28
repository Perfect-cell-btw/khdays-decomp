extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ScriptVm_ReadOperandFx32(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);
extern char *ArrayEntryPtrD0(unsigned short index);

extern void Ov023_ResolveSpeakerOperands(int ctx, int args, int id, int *kind, char *name);
extern void Ov023_ActorQueueMotion(void *entity, char *name, int kind, int a, int b, int c);

/* Script command: resolves the motion name and kind for the entity, then starts it. */
int Ov023_Cmd_StartNamedMotion(int ctx, int args) {
    int entity = ScriptVm_ReadOperandInt(ctx, (void *)args);
    int a = ScriptVm_ReadOperandInt(ctx, (void *)(args + 8));
    int b = ScriptVm_ReadOperandInt(ctx, (void *)(args + 0x20));
    int kind = -1;
    char name[0x40];
    int id = func_02020d10(ctx, entity);
    name[0] = 0;
    Ov023_ResolveSpeakerOperands(ctx, args, id, &kind, name);
    Ov023_ActorQueueMotion(*(char **)(*(char **)(ctx + 0x128) + 0x440) + id * 0x1a64,
                        name, kind, a, b, 0);
    return 1;
}
