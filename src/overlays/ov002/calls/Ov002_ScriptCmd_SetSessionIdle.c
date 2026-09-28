extern int ScriptVm_ReadOperandInt();
extern int Ov002_SetSessionIdle();

int Ov002_ScriptCmd_SetSessionIdle(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    Ov002_SetSessionIdle();
    return 1;
}
