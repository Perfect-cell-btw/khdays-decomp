/* Resolve ScriptVm_ReadOperandInt(param_1) and pass it to StoreToGlobalDblPtr; return 1. */
extern int ScriptVm_ReadOperandInt(int arg);
extern void StoreToGlobalDblPtr(int arg);
int Ov023_CmdStoreGlobalValue(int param_1) {
    StoreToGlobalDblPtr(ScriptVm_ReadOperandInt(param_1));
    return 1;
}
