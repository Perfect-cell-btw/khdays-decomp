extern int ScriptVm_ReadOperandInt();
extern int Ov002_SetGlobalFlagOnce();

int Ov002_ScriptCmd_SetGlobalFlagOnce(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    Ov002_SetGlobalFlagOnce();
    return 1;
}
