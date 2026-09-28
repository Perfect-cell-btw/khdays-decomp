extern int ScriptVm_ReadOperandInt();
extern int Ov002_SetGlobalByte1F();

int Ov002_ScriptCmd_SetGlobalByte1F(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    Ov002_SetGlobalByte1F();
    return 1;
}
