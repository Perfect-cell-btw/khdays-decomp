/* Ov023_VmWaitRecordIdle -- script VM command: wait until the record the operand names is idle.
 * An operand of -1 means "the record the last command touched", which is remembered at +0x488 of
 * the VM state. Records are 0x104 bytes apart starting at +0x30. Reports 1 (finished) as soon as
 * Ov023_IsRecordIdle says the record is idle; otherwise re-arms and reports 0. */
extern int ScriptVm_ReadOperandInt(int vm, void *op);
extern int Ov023_IsRecordIdle(int p);
extern void Slot48_StoreAtCurrentIndex(int vm, void *op);

int Ov023_VmWaitRecordIdle(int vm, void *op) {
    int idx = ScriptVm_ReadOperandInt(vm, op);
    if (idx == -1) {
        idx = *(int *)(*(int *)(vm + 0x128) + 0x488);
    }
    if (Ov023_IsRecordIdle(*(int *)(vm + 0x128) + 0x30 + (idx + idx * 64) * 4) != 0) {
        return 1;
    }
    Slot48_StoreAtCurrentIndex(vm, op);
    return 0;
}
