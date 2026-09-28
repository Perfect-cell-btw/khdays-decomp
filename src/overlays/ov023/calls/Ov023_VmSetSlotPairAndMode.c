/* Ov023_VmSetSlotPairAndMode -- script VM command: set a slot's two-word pair and its mode.
 * The pair comes from operands 2 and 3; the mode is 0 unless the fourth operand's tag is 1, in
 * which case it is read as an operand too. Always reports 1 (finished). */
extern int ScriptVm_ReadOperandInt(int vm, void *op);
extern int ScriptVm_ReadOperandFx32(int vm, void *op);
extern void Ov023_SetSlotPair(int idx, int *src);
extern void Ov023_SetSlotMode(int idx, int v);

int Ov023_VmSetSlotPairAndMode(int vm, char *op) {
    int pair[2];
    int idx;
    int mode;
    idx = ScriptVm_ReadOperandInt(vm, op);
    mode = 0;
    pair[0] = ScriptVm_ReadOperandFx32(vm, op + 8);
    pair[1] = ScriptVm_ReadOperandFx32(vm, op + 0x10);
    if (*(short *)(op + 0x18) == 1) {
        mode = ScriptVm_ReadOperandInt(vm, op + 0x18);
    }
    Ov023_SetSlotPair(idx, pair);
    Ov023_SetSlotMode(idx, mode);
    return 1;
}
