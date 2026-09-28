extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
extern void Ov002_SetWidgetStateByte(int a, int b, unsigned int flag);
/* Script op: read three operands and invoke the handler with the third reduced to a boolean. */
int Ov002_ScriptOpInvokeWithFlag(int vm, unsigned short *pc) {
    int a = ScriptVm_ReadOperandInt(vm, pc);
    int b = ScriptVm_ReadOperandInt(vm, pc + 4);
    int c = ScriptVm_ReadOperandInt(vm, pc + 8);
    Ov002_SetWidgetStateByte(a, b, (unsigned int)(c != 0));
    return 1;
}
