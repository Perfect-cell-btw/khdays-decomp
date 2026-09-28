extern int ScriptVm_ReadOperandInt(void *a, int b);
extern int ScriptVm_ReadOperandFx32(void *a, int b);
extern int func_02020400(int a, int b);
extern int Ov002_List_ScaleEntryTag(unsigned char a, unsigned short b);
extern void Ov017_thumbStep(int a, void *b, int c);

int Ov017_MarshalFxAndDispatch(void *arg1, int arg2) {
    int buf[3];
    int r6 = ScriptVm_ReadOperandInt(arg1, arg2);
    int r7 = ScriptVm_ReadOperandInt(arg1, arg2 + 8);
    buf[0] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x10);
    buf[1] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x18);
    buf[2] = ScriptVm_ReadOperandFx32(arg1, arg2 + 0x20);
    unsigned short v = (unsigned short)func_02020400(ScriptVm_ReadOperandInt(arg1, arg2 + 0x28) << 0x10, 0x168);
    int res = Ov002_List_ScaleEntryTag((unsigned char)r6, (unsigned short)r7);
    Ov017_thumbStep(res, buf, (short)v);
    return 1;
}
