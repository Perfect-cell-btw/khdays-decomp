extern int ScriptVm_ReadOperandInt();
extern int Ov002_EnterPhase();

int Ov002_ScriptCmd_EnterPhase(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    Ov002_EnterPhase();
    return 1;
}
