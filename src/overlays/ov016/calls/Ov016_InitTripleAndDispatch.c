extern int ScriptVm_ReadOperandInt(void *a, int b);
extern int ByteCode_ResolveOperand(void *a, int b);
extern int Ov016_CreateFollowerClass(unsigned short a, int *b);
extern void Ov002_SetModuleSlot(int a, int b);

int Ov016_InitTripleAndDispatch(void *arg1, int arg2) {
    int r1 = ScriptVm_ReadOperandInt(arg1, arg2);
    int r2 = ScriptVm_ReadOperandInt(arg1, arg2 + 8);
    int local = ByteCode_ResolveOperand(arg1, arg2 + 0x10);
    int r = Ov016_CreateFollowerClass((unsigned short)r2, &local);
    Ov002_SetModuleSlot(r1, r);
    return 1;
}
