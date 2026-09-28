/* Script command: reads an int operand and appends it to the pending ids; returns 1. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_AppendPendingId();

int Ov002_ScriptCmd_AppendPendingId(int arg0, void *cmd) {
        Ov002_AppendPendingId(ScriptVm_ReadOperandInt(arg0, cmd));
    return 1;
}
