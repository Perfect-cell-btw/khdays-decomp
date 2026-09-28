/* Script command: reads an int operand and dispatches the state enter; returns 1. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_DispatchStateEnter();

int Ov002_ScriptCmd_DispatchStateEnter(int arg0, void *cmd) {
        Ov002_DispatchStateEnter(ScriptVm_ReadOperandInt(arg0, cmd));
    return 1;
}
