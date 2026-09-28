extern int ScriptVm_ReadOperandInt(int vm, unsigned short *pc);
extern int func_02020400(int value, int scale);
extern void Ov002_SetRootSlot0x8d64(int value);
/* Script op: read an operand, scale it as a 16.16 fixed-point fraction of 0x168, and publish the
 * u16 result into the root context. */
int Ov002_ScriptOpScaleAndPublish(int vm, unsigned short *pc) {
    int v = ScriptVm_ReadOperandInt(vm, pc);
    Ov002_SetRootSlot0x8d64((unsigned short)func_02020400(v << 0x10, 0x168));
    return 1;
}
