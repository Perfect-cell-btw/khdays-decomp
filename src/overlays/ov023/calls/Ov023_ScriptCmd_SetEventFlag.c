/* Resolve ScriptVm_ReadOperandInt(param_1) and hand it to Ov023_SetEventFlag with flag 1. */
extern int ScriptVm_ReadOperandInt(int arg);
extern void Ov023_SetEventFlag(int a, int b);
int Ov023_ScriptCmd_SetEventFlag(int param_1) {
    Ov023_SetEventFlag(1, ScriptVm_ReadOperandInt(param_1));
    return 1;
}
