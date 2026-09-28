extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ByteCode_ResolveOperand(int ctx, void *arg);
extern int func_02020d10(int ctx, int arg);
/* Defined taking index as int: declared narrower here, which is what makes mwcc truncate the
 * argument at the call as the ROM does (declared as defined, the code comes out different). */
extern char *ArrayEntryPtrD0(unsigned short index);

/* Defined taking id as int: declared narrower here, which is what makes mwcc truncate the
 * argument at the call as the ROM does (declared as defined, the code comes out different). */
extern int LoadArrayInt244(unsigned short id);
extern int BuildSlotMask(void *flags, int mask);

/* Script predicate: true when the entity from operand 0 is live and its collision result has the
 * bit named by operand 1 set. */
int Ov023_Cmd_TestEntityCollisionBit(int ctx, int args) {
    int entity = ScriptVm_ReadOperandInt(ctx, (void *)args);
    int bit = ScriptVm_ReadOperandInt(ctx, (void *)(args + 8));
    int id = func_02020d10(ctx, entity);
    char *node = ArrayEntryPtrD0(id);
    if ((*(unsigned short *)(node + 4) & 4) == 0) {
        if ((BuildSlotMask(node + 4, LoadArrayInt244(id)) & (1 << bit)) != 0) {
            return 1;
        }
    }
    return 0;
}
