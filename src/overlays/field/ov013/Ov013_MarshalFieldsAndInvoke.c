extern int ScriptVm_ReadOperandInt(void *a, int b);
extern void Ov002_SubmitTaskNode(int a, int b, int c, void *d);

int Ov013_MarshalFieldsAndInvoke(void *arg1, int arg2) {
    int r6 = ScriptVm_ReadOperandInt(arg1, arg2);
    int r7 = ScriptVm_ReadOperandInt(arg1, arg2 + 8);
    int buf[3];
    buf[0] = ScriptVm_ReadOperandInt(arg1, arg2 + 0x10);
    buf[1] = ScriptVm_ReadOperandInt(arg1, arg2 + 0x18);
    buf[2] = ScriptVm_ReadOperandInt(arg1, arg2 + 0x20);
    Ov002_SubmitTaskNode(r6 == 0 ? 1 : 0, r7, 6, buf);
    return 1;
}
