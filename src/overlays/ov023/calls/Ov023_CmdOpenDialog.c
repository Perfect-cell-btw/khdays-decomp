/* Resolve ScriptVm_ReadOperandInt(param_1) and pass it to Ov023_OpenDialog; return 0. */
extern int ScriptVm_ReadOperandInt(int arg);
extern void Ov023_OpenDialog(int arg);
int Ov023_CmdOpenDialog(int param_1) {
    Ov023_OpenDialog(ScriptVm_ReadOperandInt(param_1));
    return 0;
}
