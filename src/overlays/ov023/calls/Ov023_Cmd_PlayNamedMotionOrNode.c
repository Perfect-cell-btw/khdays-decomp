extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);
extern char *ArrayEntryPtrD0(unsigned short index);
extern void BindAnimTrack(void *dst, int kind, void *src, short value);

extern void Ov023_ResolveSpeakerOperands(int ctx, char *args, int id, int *kind, char *name);
extern void Ov023_ActorPlayMotion(void *entity, char *name, int kind, int a, int b);
extern void Anim_BlendToTrack(void *dst, unsigned short a, void *src, short value, int b);

/* Script command: plays the named motion on a spawned entity, or falls back to driving the
 * graphics node directly when the entity is not spawned. */
int Ov023_Cmd_PlayNamedMotionOrNode(int ctx, char *args) {
    int entity = ScriptVm_ReadOperandInt(ctx, args);
    int a = ScriptVm_ReadOperandInt(ctx, args + 8);
    int b = ScriptVm_ReadOperandInt(ctx, args + 0x20);
    int kind = -1;
    char name[0x40];
    int id = func_02020d10(ctx, entity);
    char *tbl = *(char **)(*(char **)(ctx + 0x128) + 0x440);
    if (tbl != 0 && *(int *)(tbl + id * 0x1a64 + 0x15e0) != 0) {
        name[0] = 0;
        Ov023_ResolveSpeakerOperands(ctx, args, id, &kind, name);
        Ov023_ActorPlayMotion(*(char **)(*(char **)(ctx + 0x128) + 0x440) + id * 0x1a64,
                            name, kind, a, b);
    } else {
        char *node = ArrayEntryPtrD0((unsigned short)id);
        kind = ScriptVm_ReadOperandInt(ctx, args + 0x18);
        Anim_BlendToTrack(node + 4, (unsigned short)a, node + 0xe4, (short)kind, b);
    }
    return 1;
}
