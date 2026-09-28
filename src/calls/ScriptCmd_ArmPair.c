extern int ScriptVm_ReadOperandInt(int a, void *b);

int ScriptCmd_ArmPair(int param_1, int param_2) {
    *(int *)(param_1 + 0x12c) = 1;
    *(int *)(param_1 + 0x130) = ScriptVm_ReadOperandInt(param_1, (void *)param_2);
    *(int *)(param_1 + 0x134) = ScriptVm_ReadOperandInt(param_1, (void *)(param_2 + 8));
    return 3;
}
