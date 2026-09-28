/* Reads a script operand as fx32: integers are converted, fx32 values are returned as they are,
 * anything else is 0. */

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
