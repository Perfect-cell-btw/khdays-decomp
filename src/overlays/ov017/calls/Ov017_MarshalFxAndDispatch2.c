extern int ScriptVm_ReadOperandInt(void *a, int b);
extern int ScriptVm_ReadOperandFx32(void *a, int b);
extern int func_02020400(int a, int b);
extern int Ov002_GetModuleSlot(int a);
extern void Ov017_DepositCreate(int a, unsigned short b, unsigned short c, unsigned short d,
                                 int e, unsigned short f, int g, unsigned short h, void *i, int j);

int Ov017_MarshalFxAndDispatch2(void *arg1, int arg2) {
    int t0 = ScriptVm_ReadOperandInt(arg1, arg2);
    int t1 = ScriptVm_ReadOperandInt(arg1, arg2 + 8);
    int t2 = ScriptVm_ReadOperandInt(arg1, arg2 + 0x10);
    unsigned int r7 = *(unsigned int *)((char *)arg2 + 0x1c);
    unsigned int r6 = *(unsigned int *)((char *)arg2 + 0x24);
    int t3 = ScriptVm_ReadOperandInt(arg1, arg2 + 0x28);
    int buf[3];
    buf[0] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x30);
    buf[1] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x38);
    buf[2] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x40);
    int t = ScriptVm_ReadOperandInt(arg1, arg2 + 0x48);
    unsigned short fxh = (unsigned short)func_02020400(t << 0x10, 0x168);
    int res = Ov002_GetModuleSlot(t0);
    Ov017_DepositCreate(res, (unsigned short)t1, (unsigned short)t2, (unsigned short)r7,
                        (unsigned char)(unsigned short)(r7 >> 0x10),
                        (unsigned short)r6,
                        (unsigned char)(unsigned short)(r6 >> 0x10),
                        (unsigned short)t3, &buf[0], (short)fxh);
    return 1;
}
