extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
extern int Ov015_CreateTriggerClass(unsigned int id, int flag);
extern void Ov002_SetModuleSlot(int slot, int handle);
/* Script op: read a slot and an id, build the resource (id masked to u16), and publish it. */
int Ov015_ScriptOpBuildAndPublish(int vm, unsigned short *pc) {
    int slot = ScriptVm_ReadOperandInt(vm, pc);
    unsigned int id = ScriptVm_ReadOperandInt(vm, pc + 4);
    Ov002_SetModuleSlot(slot, Ov015_CreateTriggerClass(id & 0xffff, 0));
    return 1;
}
