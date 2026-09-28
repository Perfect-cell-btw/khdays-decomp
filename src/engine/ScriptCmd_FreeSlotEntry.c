/* Script command: frees and clears entry operand of the VM's table (+0x48c). */

extern int ScriptVm_ReadOperandInt(int arg, int);
extern int ZeroHalfThenFree(void *arg0);

int ScriptCmd_FreeSlotEntry(int param_1, int arg1) {
    int idx = ScriptVm_ReadOperandInt(param_1, arg1);
    void *entry = *(void **)(*(int *)(param_1 + 0x128) + idx * 4 + 0x48c);
    if (entry != 0) {
        ZeroHalfThenFree(entry);
        *(void **)(*(int *)(param_1 + 0x128) + idx * 4 + 0x48c) = 0;
    }
    return 1;
}
