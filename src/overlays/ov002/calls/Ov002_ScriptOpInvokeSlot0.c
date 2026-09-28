extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
extern void Ov002_AddMissionTally(int slot, int a, int b);
/* Script op: skip the first operand, read the next two, and invoke the handler with slot 0. */
int Ov002_ScriptOpInvokeSlot0(int vm, unsigned short *pc) {
    int a, b;
    ScriptVm_ReadOperandInt(vm, pc);
    a = ScriptVm_ReadOperandInt(vm, pc + 4);
    b = ScriptVm_ReadOperandInt(vm, pc + 8);
    Ov002_AddMissionTally(0, a, b);
    return 1;
}
