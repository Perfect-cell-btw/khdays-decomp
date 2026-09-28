extern int ScriptVm_ReadOperandInt();
extern int Ov002_World_SetByte8C9C();

int Ov002_ScriptCmd_SetWorldByte8C9C(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    Ov002_World_SetByte8C9C();
    return 1;
}
