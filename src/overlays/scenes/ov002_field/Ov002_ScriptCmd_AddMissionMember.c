/* Resolve three sub-records of param_2 (at +0, +8, +0x10) against param_1 and hand the
 * triple to the 02073ecc handler; always returns 1. */
extern int ScriptVm_ReadOperandInt(int a, int b);
extern void Ov002_ScriptAddMissionMember(int a, int b, int c);
int Ov002_ScriptCmd_AddMissionMember(int param_1, int param_2) {
    int a = ScriptVm_ReadOperandInt(param_1, param_2);
    int b = ScriptVm_ReadOperandInt(param_1, param_2 + 8);
    int c = ScriptVm_ReadOperandInt(param_1, param_2 + 0x10);
    Ov002_ScriptAddMissionMember(a, b, c);
    return 1;
}
