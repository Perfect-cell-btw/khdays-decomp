/* Script command: reads an int operand into world byte +0x8d68; returns 1. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_World_SetByte8D68();

int Ov002_ScriptCmd_SetWorldByte8D68(int arg0) {
    signed char x = ScriptVm_ReadOperandInt(arg0);
    Ov002_World_SetByte8D68(x);
    return 1;
}
