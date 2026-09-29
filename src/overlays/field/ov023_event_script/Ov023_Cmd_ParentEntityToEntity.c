extern int ScriptVm_ReadOperandInt(int ctx, void *arg);
extern int ByteCode_ResolveOperand(int ctx, void *arg);
extern int ScriptVm_ResolveActorIndex(int ctx, int arg);
/* Defined taking index as int: declared narrower here, which is what makes mwcc truncate the
 * argument at the call as the ROM does (declared as defined, the code comes out different). */
extern char *ArrayEntryPtrD0(unsigned short index);
extern int LoadArrayU8At0ce(unsigned short id);
/* Defined taking a as int, b as int: declared narrower here, which is what makes mwcc truncate the
 * argument at the call as the ROM does (declared as defined, the code comes out different). */
extern void EntityMgr_LinkChild(unsigned short a, unsigned short b, int value);
/* Defined taking id as int: declared narrower here, which is what makes mwcc truncate the
 * argument at the call as the ROM does (declared as defined, the code comes out different). */
extern void Entity_SetVisible(unsigned short id, int on);
extern void Ov023_PlaceActorModel(void *entity, int a, void *d, int h, int id);
extern void Ov023_DispatchWorkerRequest(void *entity, void *target, int id);
extern char data_02041dc8;

/* Script command: parents one entity to another. The mode operand picks which of the two keeps
 * driving its own transform. */
int Ov023_Cmd_ParentEntityToEntity(int ctx, char *args) {
    int e1 = ScriptVm_ReadOperandInt(ctx, args);
    int e2 = ScriptVm_ReadOperandInt(ctx, args + 8);
    int mode = ScriptVm_ReadOperandInt(ctx, args + 0x18);
    int value = ByteCode_ResolveOperand(ctx, args + 0x10);
    int id1 = ScriptVm_ResolveActorIndex(ctx, e1);
    int id2 = ScriptVm_ResolveActorIndex(ctx, e2);
    char *tbl;
    EntityMgr_LinkChild((unsigned short)id1, (unsigned short)id2, value);
    Entity_SetVisible((unsigned short)id1, 1);
    switch (mode) {
    case 1:
        *(unsigned short *)(ArrayEntryPtrD0((unsigned short)id2) + 4) |= 0x10;
        break;
    case 2:
        *(unsigned short *)(ArrayEntryPtrD0((unsigned short)id1) + 4) |= 8;
        break;
    }
    tbl = *(char **)(*(char **)(ctx + 0x128) + 0x440);
    if (tbl != 0) {
        Ov023_PlaceActorModel(*(char **)(*(char **)(ctx + 0x128) + 0x440) + id1 * 0x1a64,
                            0, &data_02041dc8, LoadArrayU8At0ce((unsigned short)id2), id1);
        Ov023_DispatchWorkerRequest(*(char **)(*(char **)(ctx + 0x128) + 0x440) + id1 * 0x1a64,
                            *(char **)(*(char **)(ctx + 0x128) + 0x440) + id2 * 0x1a64, id1);
    }
    return 1;
}
