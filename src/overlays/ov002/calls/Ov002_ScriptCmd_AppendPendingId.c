/* Script command: reads an int operand and appends it to the pending ids; returns 1. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_AppendPendingId();

int Ov002_ScriptCmd_AppendPendingId(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    Ov002_AppendPendingId();
    return 1;
}
