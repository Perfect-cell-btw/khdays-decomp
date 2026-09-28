/* Marshals actor fields via ScriptVm_ReadOperandInt/94 reads into a stack struct, applies
 * func_02020400(x<<0x10, 0x168) fixed-point (12.4) transform, splits packed u32 fields at
 * arg2+0x1c/0x24 into u16/u8 halves, then dispatches to a per-overlay handler with the marshaled
 * struct + Ov002_GetModuleSlot result; returns 1. */

extern int ScriptVm_ReadOperandInt(void *a, int b);
extern int ScriptVm_ReadOperandFx32(void *a, int b);
extern int func_02020400(int a, int b);
extern int Ov002_GetModuleSlot(int a);
extern void Ov015_SpawnChest(int a, unsigned short b, int c, void *d, int e, unsigned short f, int g);

int Ov015_MarshalFxAndDispatch2(void *arg1, int arg2) {
    int t0 = ScriptVm_ReadOperandInt(arg1, arg2);
    int r7 = ScriptVm_ReadOperandInt(arg1, arg2 + 8);
    int t10 = ScriptVm_ReadOperandInt(arg1, arg2 + 0x10);
    unsigned int r6 = *(unsigned int *)((char *)arg2 + 0x1c);
    int buf[3];
    buf[0] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x20);
    buf[1] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x28);
    buf[2] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x30);
    int t = ScriptVm_ReadOperandInt(arg1, arg2 + 0x38);
    int r5 = Ov002_GetModuleSlot(t0);
    int fx = func_02020400(t << 0x10, 0x168);
    Ov015_SpawnChest(r5, (unsigned short)r7, (unsigned short)t10, &buf[0], (short)fx, (unsigned short)r6, (unsigned char)(unsigned short)(r6 >> 0x10));
    return 1;
}
