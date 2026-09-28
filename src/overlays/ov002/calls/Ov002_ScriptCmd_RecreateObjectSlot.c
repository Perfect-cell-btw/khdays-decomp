extern int ScriptVm_ReadOperandInt();
extern int Ov002_RecreateObjectSlot();

int Ov002_ScriptCmd_RecreateObjectSlot(int arg0) {
    ScriptVm_ReadOperandInt(arg0);
    Ov002_RecreateObjectSlot();
    return 1;
}
