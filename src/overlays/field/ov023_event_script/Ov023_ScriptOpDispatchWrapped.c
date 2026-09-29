extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
extern unsigned int ScriptVm_ResolveActorIndex(int vm, int idx);
extern void EntityMgr_SetTransition(unsigned int a, int b, int c);
/* Script op: read an int operand, resolve it as a wrapped index, dispatch it (u16); return 1. */
int Ov023_ScriptOpDispatchWrapped(int vm, unsigned short *pc) {
    int idx = ScriptVm_ReadOperandInt(vm, pc);
    unsigned int resolved = ScriptVm_ResolveActorIndex(vm, idx);
    EntityMgr_SetTransition(resolved & 0xffff, 0, 0);
    return 1;
}
