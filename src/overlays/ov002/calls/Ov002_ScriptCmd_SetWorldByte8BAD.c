extern int ScriptVm_ReadOperandInt();
extern int Ov002_World_SetByte8BAD();

int Ov002_ScriptCmd_SetWorldByte8BAD(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    Ov002_World_SetByte8BAD();
    return 1;
}
