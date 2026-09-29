extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ByteCode_ResolveOperand(int ctx, void *arg);
extern int ScriptVm_ResolveActorIndex(int ctx, int arg);
extern char *ArrayEntryPtrD0(int index);

extern int LoadArrayInt244(int id);
extern int BuildSlotMask(void *flags, int mask);

/* Script predicate: true when the entity from operand 0 is live and its collision result has the
 * bit named by operand 1 set. */
int Ov023_Cmd_TestEntityCollisionBit(int ctx, int args) {
    int entity = ScriptVm_ReadOperandInt(ctx, (void *)args);
    int bit = ScriptVm_ReadOperandInt(ctx, (void *)(args + 8));
    int id = ScriptVm_ResolveActorIndex(ctx, entity);
    char *node = ArrayEntryPtrD0((unsigned short)id);
    if ((*(unsigned short *)(node + 4) & 4) == 0) {
        /* Written as a mask where another call truncates with a cast: mwcc would otherwise compute the
         * truncation once and keep it, while the ROM truncates again at each call. */
        if ((BuildSlotMask(node + 4, LoadArrayInt244(id & 0xffff)) & (1 << bit)) != 0) {
            return 1;
        }
    }
    return 0;
}
