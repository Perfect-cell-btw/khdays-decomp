/* Resolve ScriptVm_ReadOperandInt(param_1) and hand it to Ov023_SetEventFlag with flag 0. */
extern int ScriptVm_ReadOperandInt(int arg, int);
extern void Ov023_SetEventFlag(int a, int b);
int Ov023_CmdSetEventFlag(int param_1, int arg1) {
    Ov023_SetEventFlag(0, ScriptVm_ReadOperandInt(param_1, arg1));
    return 1;
}
