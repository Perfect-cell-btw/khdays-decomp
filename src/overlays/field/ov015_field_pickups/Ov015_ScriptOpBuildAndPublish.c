extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
extern int Ov015_CreateTriggerClass(int nCount, const void *pDesc);
extern void Ov002_SetModuleSlot(int slot, int handle);
/* Script op: read a slot and an entry count, build the trigger class (count masked to u16), and publish it. */
int Ov015_ScriptOpBuildAndPublish(int vm, unsigned short *pc) {
    int slot = ScriptVm_ReadOperandInt(vm, pc);
    unsigned int nCount = ScriptVm_ReadOperandInt(vm, pc + 4);
    Ov002_SetModuleSlot(slot, Ov015_CreateTriggerClass(nCount & 0xffff, 0));
    return 1;
}
