/* Resolve two sub-records of param_2 (at +0 and +8) against param_1 and hand the pair to
 * the 0206ca3c handler; always returns 1. */
extern int ScriptVm_ReadOperandInt(int a, int b);
extern void Ov002_Event_SetParams(int a, int b);
int Ov002_ScriptCmd_SetEventParams(int param_1, int param_2) {
    int a = ScriptVm_ReadOperandInt(param_1, param_2);
    int b = ScriptVm_ReadOperandInt(param_1, param_2 + 8);
    Ov002_Event_SetParams(a, b);
    return 1;
}
