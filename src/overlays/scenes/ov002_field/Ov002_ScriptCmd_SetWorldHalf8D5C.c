/* Script command: stores the operand in the world's halfword +0x8d5c; returns 1. */

extern int ScriptVm_ReadOperandInt();
extern int Ov002_World_SetHalf8D5C();

int Ov002_ScriptCmd_SetWorldHalf8D5C(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    Ov002_World_SetHalf8D5C();
    return 1;
}
