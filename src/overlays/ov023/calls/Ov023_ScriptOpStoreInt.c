extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
/* Script op: read an int operand and store it into the VM's register block (*(vm+0x128))+0x484. */
int Ov023_ScriptOpStoreInt(int vm, unsigned short *pc) {
    int v = ScriptVm_ReadOperandInt(vm, pc);
    *(int *)(*(int *)(vm + 0x128) + 0x484) = v;
    return 1;
}
