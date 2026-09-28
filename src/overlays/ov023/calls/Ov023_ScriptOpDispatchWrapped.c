extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
extern unsigned int func_02020d10(int vm, int idx);
extern void EntityMgr_SetTransition(unsigned int a, int b, int c);
/* Script op: read an int operand, resolve it as a wrapped index, dispatch it (u16); return 1. */
int Ov023_ScriptOpDispatchWrapped(int vm, unsigned short *pc) {
    int idx = ScriptVm_ReadOperandInt(vm, pc);
    unsigned int resolved = func_02020d10(vm, idx);
    EntityMgr_SetTransition(resolved & 0xffff, 0, 0);
    return 1;
}
