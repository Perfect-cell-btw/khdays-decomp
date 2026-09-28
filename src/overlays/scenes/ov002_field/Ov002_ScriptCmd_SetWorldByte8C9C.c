/* Script command: reads an int operand into world byte +0x8c9c; returns 1. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_World_SetByte8C9C();

int Ov002_ScriptCmd_SetWorldByte8C9C(int arg0, void *cmd) {
        Ov002_World_SetByte8C9C(ScriptVm_ReadOperandInt(arg0, cmd));
    return 1;
}
