extern int ScriptVm_ReadOperandInt();

int Ov002_ScriptCmd_SkipIntOperand_2(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    return 1;
}
