extern int ScriptVm_ReadOperandInt();
extern int Ov002_NotifyNodesOfKind();

int Ov002_ScriptCmd_NotifyNodesOfKind(int arg0) {
    unsigned short x = ScriptVm_ReadOperandInt(arg0);
    Ov002_NotifyNodesOfKind(x);
    return 1;
}
