extern int ScriptVm_ReadOperandInt();
extern int Ov002_AdvanceRosterSetup();

int Ov002_ScriptCmd_AdvanceRosterSetup(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    return Ov002_AdvanceRosterSetup() != 0;
}
