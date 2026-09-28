extern int ScriptVm_ReadOperandInt();
extern int Ov002_CreateFieldContext();

int Ov002_ScriptCmd_CreateFieldContext(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    Ov002_CreateFieldContext();
    return 1;
}
