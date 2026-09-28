extern int ScriptVm_ReadOperandFx32(int vm, unsigned short *pc);
extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
/* Script op: read an fx32 value and a slot index, store the value into the VM's per-slot block
 * (*(vm+0x128) + idx*0x104 + 0x11c). */
int Ov023_ScriptOpStoreSlotFx32(int vm, unsigned short *pc) {
    int value = ScriptVm_ReadOperandFx32(vm, pc);
    int idx = ScriptVm_ReadOperandInt(vm, pc + 4);
    *(int *)(*(int *)(vm + 0x128) + idx * 0x104 + 0x11c) = value;
    return 1;
}
