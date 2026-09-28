/* Script command: consumes one int operand and does nothing else; returns 1. */

extern int ScriptVm_ReadOperandInt();

int Ov002_ScriptCmd_SkipIntOperand(int arg0, int arg1) {
    ScriptVm_ReadOperandInt(arg0, arg1);
    return 1;
}
