/* Script command: reads an int operand and sets that global flag once; returns 1. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_SetGlobalFlagOnce();

int Ov002_ScriptCmd_SetGlobalFlagOnce(int arg0, void *cmd) {
        Ov002_SetGlobalFlagOnce(ScriptVm_ReadOperandInt(arg0, cmd));
    return 1;
}
