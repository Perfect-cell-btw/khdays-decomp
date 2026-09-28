/* Script command: reads an int operand and sets the session idle; returns 1. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_SetSessionIdle();

int Ov002_ScriptCmd_SetSessionIdle(int arg0, void *cmd) {
        Ov002_SetSessionIdle(ScriptVm_ReadOperandInt(arg0, cmd));
    return 1;
}
