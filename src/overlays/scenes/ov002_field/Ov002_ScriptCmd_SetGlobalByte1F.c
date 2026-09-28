/* Script command: reads an int operand into global byte 0x1f; returns 1. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_SetGlobalByte1F();

int Ov002_ScriptCmd_SetGlobalByte1F(int arg0, void *cmd) {
        Ov002_SetGlobalByte1F(ScriptVm_ReadOperandInt(arg0, cmd));
    return 1;
}
