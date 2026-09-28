extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
extern int Ov023_IsRecordIdle(int slot);
/* Script op: read a slot index (-1 selects the VM's current slot at +0x488), then run the
 * predicate on that slot's block; returns 1 when it holds. */
int Ov023_ScriptOpTestSlot(int vm, unsigned short *pc) {
    int idx = ScriptVm_ReadOperandInt(vm, pc);
    if (idx == -1) {
        idx = *(int *)(*(int *)(vm + 0x128) + 0x488);
    }
    if (Ov023_IsRecordIdle(*(int *)(vm + 0x128) + 0x30 + idx * 0x104) != 0) {
        return 1;
    }
    return 0;
}
