extern int ScriptVm_ReadOperandInt();
extern int Ov002_InitObjectTables();

int Ov002_ScriptCmd_InitObjectTables(int arg0, int arg1) {
    int a = ScriptVm_ReadOperandInt(arg0, arg1);
    int b = ScriptVm_ReadOperandInt(arg0, arg1 + 8);
    Ov002_InitObjectTables(a, b);
    return 1;
}
