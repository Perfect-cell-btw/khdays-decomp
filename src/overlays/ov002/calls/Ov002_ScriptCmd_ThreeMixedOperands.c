/* Resolve three sub-records of param_2 (at +0, +8, +0x10) against param_1 via distinct
 * resolvers and hand the triple to the 0206e1a4 handler; always returns 1. */
extern int ScriptVm_ReadOperandInt(int a, int b);
extern int ByteCode_ResolveOperand(int a, int b);
extern int ScriptVm_ReadOperandFx32(int a, int b);
extern void Ov002_ScriptSpawnTimedSet(int a, int b, int c);
int Ov002_ScriptCmd_ThreeMixedOperands(int param_1, int param_2) {
    int a = ScriptVm_ReadOperandInt(param_1, param_2);
    int b = ByteCode_ResolveOperand(param_1, param_2 + 8);
    int c = ScriptVm_ReadOperandFx32(param_1, param_2 + 0x10);
    Ov002_ScriptSpawnTimedSet(a, b, c);
    return 1;
}
