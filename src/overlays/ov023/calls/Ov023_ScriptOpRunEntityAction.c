extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
extern int Ov023_IsSlotFree(int entry, int arg);
/* Script op: read an entity index and an argument, then run the action on that entity's entry
 * (*(vm+0x128)+0x440, stride 0x1a64); returns 1 on success. */
int Ov023_ScriptOpRunEntityAction(int vm, unsigned short *pc) {
    int idx = ScriptVm_ReadOperandInt(vm, pc);
    int arg = ScriptVm_ReadOperandInt(vm, pc + 4);
    if (Ov023_IsSlotFree(*(int *)(*(int *)(vm + 0x128) + 0x440) + idx * 0x1a64, arg) != 0) {
        return 1;
    }
    return 0;
}
