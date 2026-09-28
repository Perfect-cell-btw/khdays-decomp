/* Script command: reads an int operand and recreates that object slot; returns 1. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_RecreateObjectSlot();

int Ov002_ScriptCmd_RecreateObjectSlot(int arg0, void *cmd) {
        Ov002_RecreateObjectSlot(ScriptVm_ReadOperandInt(arg0, cmd));
    return 1;
}
