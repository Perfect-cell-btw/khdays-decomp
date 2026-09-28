extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
extern unsigned int *ByteCode_ResolveOperand(int vm, unsigned short *pc);
extern short LoadGlobalU16At0(void);
extern void Ov023_LoadSecondaryScript(int a, unsigned int *b);
/* Script op: read an operand and a resolved pointer; only act when the current opcode is 0xc. */
int Ov023_ScriptOpActWhenOpcodeC(int vm, unsigned short *pc) {
    int a = ScriptVm_ReadOperandInt(vm, pc);
    unsigned int *p = ByteCode_ResolveOperand(vm, pc + 4);
    if (LoadGlobalU16At0() != 0xc) {
        return 1;
    }
    Ov023_LoadSecondaryScript(a, p);
    return 1;
}
