/* Resolve two sub-records of param_2 (at +0 and +8) against param_1 via distinct resolvers
 * and hand the pair to the 02072b40 handler; always returns 1. */
extern int ScriptVm_ReadOperandInt(int a, int b);
extern int ScriptVm_ReadOperandFx32(int a, int b);
extern void Ov002_SetLinkModeAndValue(int a, int b);
int Ov002_ScriptCmd_SetLinkMode(int param_1, int param_2) {
    int a = ScriptVm_ReadOperandInt(param_1, param_2);
    int b = ScriptVm_ReadOperandFx32(param_1, param_2 + 8);
    Ov002_SetLinkModeAndValue(a, b);
    return 1;
}
