extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
extern void Ov002_DeliverEventLocalFlag(unsigned int negated, unsigned int arg);
/* Script op: read two operands and invoke the handler with the first inverted to a boolean. */
int Ov002_ScriptOpSetFlagInverted(int vm, unsigned short *pc) {
    int a = ScriptVm_ReadOperandInt(vm, pc);
    unsigned int b = ScriptVm_ReadOperandInt(vm, pc + 4);
    Ov002_DeliverEventLocalFlag((unsigned int)(a == 0), b);
    return 1;
}
