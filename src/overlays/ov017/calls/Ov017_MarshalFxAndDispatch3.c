/* Marshals actor fields via ScriptVm_ReadOperandInt/94 reads into a stack struct, applies
 * func_02020400(x<<0x10, 0x168) fixed-point (12.4) transform, splits packed u32 fields at
 * arg2+0x1c/0x24 into u16/u8 halves, then dispatches to a per-overlay handler with the marshaled
 * struct + Ov002_GetModuleSlot result; returns 1. */

extern int ScriptVm_ReadOperandInt(void *a, int b);
extern int ScriptVm_ReadOperandFx32(void *a, int b);
extern int func_02020400(int a, int b);
extern int Ov002_GetModuleSlot(int a);
extern void Ov017_ItemCreate(int a, unsigned short b, unsigned short c, void *d,
                                 int e, unsigned short f, int g, unsigned short h, int i, int j);

int Ov017_MarshalFxAndDispatch3(void *arg1, int arg2) {
    int a = ScriptVm_ReadOperandInt(arg1, arg2 + 0x28);
    int buf[3];
    buf[0] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x30);
    buf[1] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x38);
    buf[2] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x40);
    unsigned int r7 = *(unsigned int *)((char *)arg2 + 0x1c);
    unsigned int r6 = *(unsigned int *)((char *)arg2 + 0x24);
    int t = ScriptVm_ReadOperandInt(arg1, arg2 + 0x48);
    unsigned short fxh = (unsigned short)func_02020400(t << 0x10, 0x168);
    int res = Ov002_GetModuleSlot(ScriptVm_ReadOperandInt(arg1, arg2));
    int c = ScriptVm_ReadOperandInt(arg1, arg2 + 8);
    int d = ScriptVm_ReadOperandInt(arg1, arg2 + 0x10);
    Ov017_ItemCreate(res, (unsigned short)c, (unsigned short)d, &buf[0],
                        (short)fxh, (unsigned short)r7, (unsigned char)(unsigned short)(r7 >> 0x10),
                        (unsigned short)r6, (unsigned char)(unsigned short)(r6 >> 0x10),
                        (short)a);
    return 1;
}
