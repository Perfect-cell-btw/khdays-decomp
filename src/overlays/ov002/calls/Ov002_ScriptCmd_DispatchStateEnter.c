/* Script command: reads an int operand and dispatches the state enter; returns 1. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_DispatchStateEnter();

int Ov002_ScriptCmd_DispatchStateEnter(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    Ov002_DispatchStateEnter();
    return 1;
}
