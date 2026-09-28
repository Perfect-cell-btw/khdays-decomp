extern short *ScriptVm_ResolveOperand(void);

int ScriptVm_ReadOperandFx32(void) {
    short *ptr = ScriptVm_ResolveOperand();
    int value = 0;

    if (ptr[0] == 1) {
        return *(int *)(ptr + 2) << 12;
    }

    if (ptr[0] == 0x10) {
        value = *(int *)(ptr + 2);
    }

    return value;
}
