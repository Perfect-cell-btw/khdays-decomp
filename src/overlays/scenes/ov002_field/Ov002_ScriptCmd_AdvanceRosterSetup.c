/* Script command: advances the roster setup; returns whether it progressed. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_AdvanceRosterSetup();

int Ov002_ScriptCmd_AdvanceRosterSetup(int arg0, void *cmd) {
        return Ov002_AdvanceRosterSetup(ScriptVm_ReadOperandInt(arg0, cmd)) != 0;
}
