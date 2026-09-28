/* Script command: creates an entity in a module slot's context with the operands; returns 1. */

extern int ScriptVm_ReadOperandInt(void *a, int b);
extern int Ov002_GetModuleSlot(int a);
extern void Ov020_CreateEntity(int a, int b, int c, unsigned short d, int e);

int Ov020_MarshalAndDispatch(void *arg1, int arg2) {
    int r7 = ScriptVm_ReadOperandInt(arg1, arg2);
    int r6 = ScriptVm_ReadOperandInt(arg1, arg2 + 8);
    int r4 = ScriptVm_ReadOperandInt(arg1, arg2 + 0x10);
    unsigned int r5 = *(unsigned int *)((char *)arg2 + 0x1c);
    int res = Ov002_GetModuleSlot(r7);
    Ov020_CreateEntity(res, (unsigned short)r6, (unsigned short)r4, (unsigned short)r5,
                       (unsigned char)(unsigned short)(r5 >> 0x10));
    return 1;
}
