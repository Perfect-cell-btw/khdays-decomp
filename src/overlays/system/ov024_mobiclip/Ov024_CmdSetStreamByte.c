/* Resolve ScriptVm_ReadOperandInt(param_1) and hand it to StampByteAndInvokeSubStructAt with mode 0; return 1. */
extern int ScriptVm_ReadOperandInt(int arg, int);
extern void StampByteAndInvokeSubStructAt(int a, int b);
int Ov024_CmdSetStreamByte(int param_1, int arg1) {
    StampByteAndInvokeSubStructAt(0, ScriptVm_ReadOperandInt(param_1, arg1));
    return 1;
}
