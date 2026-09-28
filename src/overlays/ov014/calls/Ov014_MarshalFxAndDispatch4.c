extern int ScriptVm_ReadOperandInt(void *a, int b);
extern int ScriptVm_ReadOperandFx32(void *a, int b);
extern int func_02020400(int a, int b);
extern int Ov002_GetModuleSlot(int a);
extern void Ov014_SpawnElement(int a, unsigned short b, unsigned short c, unsigned short d,
                                 int e, void *f, int g, int h);

int Ov014_MarshalFxAndDispatch4(void *arg1, int arg2) {
    int t0 = ScriptVm_ReadOperandInt(arg1, arg2);
    int r7 = ScriptVm_ReadOperandInt(arg1, arg2 + 8);
    int t14 = ScriptVm_ReadOperandInt(arg1, arg2 + 0x10);
    unsigned int r6 = *(unsigned int *)((char *)arg2 + 0x1c);
    int buf[3];
    buf[0] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x20);
    buf[1] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x28);
    buf[2] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x30);
    int t18 = ScriptVm_ReadOperandInt(arg1, arg2 + 0x38);
    int last = ScriptVm_ReadOperandInt(arg1, arg2 + 0x40);
    int res = Ov002_GetModuleSlot(t0);
    int fx = func_02020400(t18 << 0x10, 0x168);
    Ov014_SpawnElement(res, (unsigned short)r7, (unsigned short)t14, (unsigned short)r6,
                        (unsigned char)(unsigned short)(r6 >> 0x10), &buf[0], (short)fx, last);
    return 1;
}
